// Fill out your copyright notice in the Description page of Project Settings.


#include "TentacleBase.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "HealthComponent.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TentacleSection.h"

// Sets default values
ATentacleBase::ATentacleBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bRegenerateLimb = false;
	bCalculatePoints = false;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	ConstructLimb();

	MinSample = 0.001f;
	MaxSample = 1.0f; // values above 1 tend to overshoot, not desirable, but they do learn faster. This makes it a very suitable default, but still open to alteration. 
	// 0.05 default before dynamism
	MinLearningRate = 0.02f;
	MaxLearningRate = 0.085f; // this is quite fast, but you could reasonably want faster. 

	MaxDynamismRange = 50.0f;
	MinDynamismRange = 10.0f;
	EarlyTerminationDistance = 0.8f;

	Damage = 15.0f;
	PushForceMagnitude = 10.0f;

	NumberOfSections = 5;
	SectionLength = 0.3f;
	MaxThickness = 0.35f;
	MinThickness = 0.2f;
	// base color: #a701fb
	// tip color:  #fcfb01
}

// Called when the game starts or when spawned
void ATentacleBase::BeginPlay()
{
	Super::BeginPlay();
	if (bRunInPlaymode)
		bRunIKRealtime = true;
	AActor* PlayerTarget = nullptr;// = Cast<AActor>();
	for (TActorIterator<APlayerCharacter> It(GetWorld()); It; ++It)
	{
		PlayerTarget = *It;
	}
	if (PlayerTarget) // just for testing, set the target to a player when they spawn
		TargetActor = PlayerTarget;
	// UGameplayStatics::GetPlayerController(GetWorld(), 0) // returns an actor but its just a place in space for some reason
}

// Called every frame
void ATentacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateLimb) {
		bRegenerateLimb = false;
		ConstructLimb();
	}
	if (bCalculatePoints) {
		CalculatePoints();
		bCalculatePoints = false;
	}
	if (bCalculateError) {
		TArray<float> TestAnglesX = GetAngles(0);
		TArray<float> TestAnglesY = GetAngles(1);
		FString xAnglesString = "";
		FString yAnglesString = "";
		for (float f : TestAnglesX)
			xAnglesString += FString::SanitizeFloat(f) + ", ";
		for (float f : TestAnglesY)
			yAnglesString += FString::SanitizeFloat(f) + ", ";
		UE_LOG(LogTemp, Warning, TEXT("x angles: %s,	y angles: %s"), *xAnglesString, *yAnglesString)
			float DistX = DistanceFromTarget(TargetActor->GetActorLocation(), TestAnglesX, 0);
		float DistY = DistanceFromTarget(TargetActor->GetActorLocation(), TestAnglesY, 1);
		UE_LOG(LogTemp, Warning, TEXT("Calculating error: on x:%f,	on y: %f"), DistX, DistY)
			FRotator lastRot = Sections[Sections.Num() - 1]->GetActorRotation();
		UE_LOG(LogTemp, Warning, TEXT("Last rotator: %s"), *lastRot.ToString())
			bCalculateError = false;
	}
	if (bRunIKOnce) {
		IK(TargetActor->GetActorLocation());
		bRunIKOnce = false;
	}
	if (bDisplayRotations) {
		bDisplayRotations = false;
		TArray<float> TestAnglesX = GetAngles(0);
		TArray<float> TestAnglesY = GetAngles(1);
		FString xAnglesString = "";
		FString yAnglesString = "";
		for (float f : TestAnglesX)
			xAnglesString += FString::SanitizeFloat(f) + ", ";
		for (float f : TestAnglesY)
			yAnglesString += FString::SanitizeFloat(f) + ", ";
		UE_LOG(LogTemp, Warning, TEXT("x angles: %s,	y angles: %s"), *xAnglesString, *yAnglesString)
			for (int16 i = 0; i < Sections.Num(); i++) {
				FRotator iRot = Sections[i]->GetActorRotation();
				UE_LOG(LogTemp, Warning, TEXT("Rotator[%i]: %s"), i, *iRot.ToString())
			}
	}

	if (bRunIKRealtime) {
		bool ReachSuccess = false;
		if (TargetActor)
			ReachSuccess = IK(TargetActor->GetActorLocation());
		if (ReachSuccess) {// Try to get the actor, damage them and push them away
			// Get their character
			ACharacter* StruckCharacter = Cast<ACharacter>(TargetActor);
			if (StruckCharacter) {
				// launch character
				FVector LaunchVelo = (FindEndLocation() - TargetActor->GetActorLocation()) * PushForceMagnitude;
				StruckCharacter->LaunchCharacter(LaunchVelo, true, true);
				// damage character
				APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(StruckCharacter);
				if (PlayerCharacter) {
					//UHealthComponent* HealthComp = PlayerCharacter->GetOwner()->GetComponentByClass<UHealthComponent>();
					UHealthComponent* HealthComp = PlayerCharacter->GetOwner()->FindComponentByClass<UHealthComponent>();
					if (HealthComp) {
						HealthComp->OnTakeDamage(Damage);
						UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Complete success on damaging and pushing in terms of code progression at least. ")) // delete this after debugging
					} else
						UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not get Health Component"))
				} else
					UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not convert ACharacter to PlayerCharacter"))
			} else 
				UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not convert target actor to ACharacter. "))
			

		}
	}
}

void ATentacleBase::HurtAndPushPlayer(const FVector& Position, AActor* HitActor) {
	ACharacter* StruckCharacter = Cast<ACharacter>(HitActor);
	if (StruckCharacter) {
		// launch character
		//FVector LaunchVelo = (Position - HitActor->GetActorLocation()) * PushForceMagnitude;
		FVector LaunchVelo = (HitActor->GetActorLocation() - Position) * PushForceMagnitude;
		//UE_LOG(LogTemp, Warning, TEXT("Tentacle is pushing actor at: %s in direction: %s"), *HitActor->GetActorLocation().ToString(), *LaunchVelo.ToString())
		StruckCharacter->LaunchCharacter(LaunchVelo, true, true);
		// damage character
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(StruckCharacter);
		if (PlayerCharacter) {
			//UHealthComponent* HealthComp = PlayerCharacter->GetOwner()->GetComponentByClass<UHealthComponent>();
			//UHealthComponent* HealthComp = PlayerCharacter->GetOwner()->FindComponentByClass<UHealthComponent>();
			UHealthComponent* HealthComp = PlayerCharacter->HealthComponent;
			if (HealthComp) {
				if (HealthComp->CurrentHealth > 0)
					HealthComp->OnTakeDamage(Damage);
				//UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Complete success on damaging and pushing in terms of code progression at least. ")) // delete this after debugging
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not get Health Component"))
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not convert ACharacter to PlayerCharacter"))
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Tentacle Base - Could not convert target actor to ACharacter. "))
}

void ATentacleBase::ConstructLimb() {
	if (Sections.Num() > 0) {
		for (AActor* Actor : Sections)
			if (Actor)
				Actor->Destroy();
	}
	else UE_LOG(LogTemp, Warning, TEXT("Sections already empty"))
		Sections.Empty();
	FAttachmentTransformRules AttachRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, true);
	for (int32 i = 0; i < NumberOfSections; i++) { // sequentially generate the tentacle sections
		float IndexRatio = (float)i / (float)NumberOfSections;

		// create a new section. Fill its member variables. Let it initialse. 
		FVector SpawnLoc = GetActorLocation();
		ATentacleSection* NewSection = GetWorld()->SpawnActor<ATentacleSection>(SpawnLoc, FRotator::ZeroRotator, FActorSpawnParameters());
		NewSection->Length = SectionLength;
		NewSection->Thickness = MaxThickness;
		NewSection->Base = this;
		// Fill in the colours for the materials. FLinearColour can be used in a lerp but not FColor. 
		NewSection->BaseColour = (FMath::Lerp(BaseColour.ReinterpretAsLinear(), TipColour.ReinterpretAsLinear(), IndexRatio).ToFColor(true));
		NewSection->TipColour = (FMath::Lerp(BaseColour.ReinterpretAsLinear(), TipColour.ReinterpretAsLinear(), IndexRatio + (1.0f / (float)NumberOfSections)).ToFColor(true));

		// Section now set up, add it to the array, parent it to previous section.
		Sections.Add(NewSection);
		if (i > 0) { // Attach to the previous section
			AActor* ParentActor = Cast<AActor>(Sections[i - 1]);
			if (ParentActor)
				NewSection->AttachToActor(ParentActor, AttachRules);
		}
		else { // if it is the first section attach it to this object (ATentacleBase)
			NewSection->AttachToActor(this, AttachRules);
		}
		// If it is to be tapered use that function, else use the standard one. 
		if (bTaperThickness)
			NewSection->GenerateSection(i, FMath::Lerp(MinThickness, MaxThickness, (1 - IndexRatio)));
		else
			NewSection->GenerateSection(i);
	}
}

void ATentacleBase::SetFromRarity(EWeaponPickupRarity Rarity, AActor* Target) {
	switch (Rarity) {
		case EWeaponPickupRarity::COMMON:
			NumberOfSections = 5;
			SectionLength = 0.3f;
			MaxThickness = 0.35f;
			MinThickness = 0.2f;
			BaseColour = FColor(2, 32, 8);
			TipColour = FColor(3, 77, 15);
			Damage = 15.0f;
			MaxHealth = 70.0f;
			break;
		case EWeaponPickupRarity::RARE:
			NumberOfSections = 6;
			SectionLength = 0.28f;
			MaxThickness = 0.36f;
			MinThickness = 0.18f;
			BaseColour = FColor(7, 56, 38);
			TipColour = FColor(224,5,5);
			Damage = 20.0f;
			MaxHealth = 85.0f;
			MaxLearningRate = 0.1f;
			break;
		case EWeaponPickupRarity::MASTER:
			NumberOfSections = 6;
			SectionLength = 0.28f;
			MaxThickness = 0.36f;
			MinThickness = 0.18f;
			BaseColour = FColor(4,10,4);
			TipColour = FColor(2,5,2);
			Damage = 25.0f;
			MaxHealth = 100.0f;
			MaxLearningRate = 0.15f;
			break;
		case EWeaponPickupRarity::LEGENDARY:
			NumberOfSections = 7;
			SectionLength = 0.32f;
			MaxThickness = 0.45f;
			MinThickness = 0.24f;
			BaseColour = FColor(168,1,252);
			TipColour = FColor(252, 252, 1);
			Damage = 35.0f;
			MaxHealth = 125.0f;
			MaxLearningRate = 0.4f;
			break;
		CurrentHealth = MaxHealth;
		bAlive = true;
		TargetActor = Target;
		bRunIKRealtime = true;
		ConstructLimb();
		//void SetParameters(int NumberOfSections_, float SectionLength_, float MaxThickness_, float MinThickness_, FColor BaseColor_, FColor TipColor_);
	}
}

void ATentacleBase::OnTakeDamage(float DamageReceived) {
	CurrentHealth -= DamageReceived;
	if (CurrentHealth <= 0.0f)
		OnDeath();
}

void ATentacleBase::OnDeath() {
	bAlive = false;
	bRunIKRealtime = false;
	if (Sections.Num() > 0) {
		for (AActor* Actor : Sections)
			if (Actor)
				Actor->Destroy();
	}
	else UE_LOG(LogTemp, Warning, TEXT("Sections already empty"))
	Sections.Empty();
	// *** alert the AI manager that this has been killed
}

void ATentacleBase::SetParameters_Implementation(int NumberOfSections_, float SectionLength_, float MaxThickness_, float MinThickness_, FColor BaseColor_, FColor TipColor_) {
	NumberOfSections = NumberOfSections_;
	SectionLength = SectionLength_;
	MaxThickness = MaxThickness_;
	MinThickness = MinThickness_;
	BaseColour = BaseColor_;
	TipColour = TipColor_;
	bTaperThickness = true;

	bRunInPlaymode = true;
	ConstructLimb();
}

//bool ATentacleBase::ServerIK_Implementation(FVector& const Target) {
//	return IK(TargetActor->GetActorLocation());
//}

FVector ATentacleBase::FindEndLocation() { // Return the worldspace location of the end effector. 
	if (Sections.Num() > 0)
		return Sections[Sections.Num() - 1]->FindSectionEnd();
	else
		return GetActorLocation();
}

float ATentacleBase::DistanceFromTarget(FVector Target) { // Find the euclidean distance between the argument and the end effector
	return FVector::Dist(Target, FindEndLocation());
}

float ATentacleBase::DistanceFromTarget(FVector Target, TArray<float> angles, int axis) { // Using given angles along axis, find the euclidean distance from the argument to the end effector
	// Axes 0-Roll, 1-Pitch, 2-Yaw
	FVector SecStart = Sections[0]->GetActorLocation();
	FVector SecEnd;
	for (int i = 0; i < Sections.Num(); i++) {
		SecEnd = (Sections[i]->CalculateEndFromPoint(SecStart, angles[i], axis));
		SecStart = SecEnd;
	}
	if (bCalculatePoints)
		UE_LOG(LogTemp, Warning, TEXT("Distance From Target thinks the end effector location is: %s"), *SecEnd.ToString())
		return FVector::Dist(Target, SecEnd);
}

TArray<float> ATentacleBase::GetAngles(int axis) { // Returns an array of angles along a given axis sources from each section's FRotator. 
	// Axes 0-Roll, 1-Pitch, 2-Yaw
	TArray<float> Angles = TArray<float>();
	for (int i = 0; i < Sections.Num(); i++) {
		if (axis == 0)
			Angles.Add(Sections[i]->GetActorRotation().Roll);
		else if (axis == 1)
			Angles.Add(Sections[i]->GetActorRotation().Pitch);
		else if (axis == 2)
			Angles.Add(Sections[i]->GetActorRotation().Yaw);
	}
	return Angles;
}

float ATentacleBase::PartialGradient(FVector Target, TArray<float> Angles, int Axis, int Index) { // Used to tell the tentacles which angle way to rotate
	// Returns the partial gradient of the soft function DistanceFromTarget. 
	// to be used in a for loop, ie index = i
	float CurrentAngle = Angles[Index];
	float CurrentError = DistanceFromTarget(Target, Angles, Axis);
	for (int Sect = Index; Sect < Sections.Num(); Sect++) // to test error with an altered angle. For loop to pass it forward. 
		Angles[Sect] += DynamicSamplingDistance;
	float SampledError = DistanceFromTarget(Target, Angles, Axis);
	// Gradient = (f(x+h) - f(x))/h => (error with sampling - current error) / sampling distance	[ie first principles. lim(h)->0 not necessary]
	float Gradient = (SampledError - CurrentError) / DynamicSamplingDistance;
	for (int Sect = Index; Sect < Sections.Num(); Sect++) // revert changes. (we are just testing not wanting to truly assign)
		Angles[Sect] -= DynamicSamplingDistance;
	if (bRunIKOnce || bCalculateError)
		UE_LOG(LogTemp, Warning, TEXT("Partial gradient[%i], axis: %i,	curError: %f,	sampledError: %f,	gradient: %f"), Index, Axis, CurrentError, SampledError, Gradient)
		return Gradient;
}

bool ATentacleBase::IK(FVector Target) { // Rotates the tentacle sections towards the target. Returns true if it is close enough, else false. 
	TArray<float> Angles;
	UpdateSamplingDistance(); // Update the dynamic amounts 
	UpdateLearningRate();
	if (FVector::Dist(Target, FindEndLocation()) <= EarlyTerminationDistance) // If it is close enough early terminate and return true. 
		return true;
	for (int Axis = 0; Axis <= 2; Axis++) { // IK is run once per axis, to determine how the rotation needs to change on the per axis basis. // Axes 0-Roll, 1-Pitch, 2-Yaw
		Angles = GetAngles(Axis);
		if (bRunIKOnce)
			UE_LOG(LogTemp, Warning, TEXT("Running IK on axis: %i"), Axis)
			for (int Index = 0; Index < Sections.Num(); Index++) { // Iterate through each section to determine how it should move. Starting from the first and following through to the last
				float PartialGrad = PartialGradient(Target, Angles, Axis, Index);
				float PreservedAngle = Angles[Index]; //just for debug. not used
				for (int Sect = Index; Sect < Sections.Num(); Sect++) // Apply this to this and future joints/sections. 
					Angles[Sect] += -DynamicLearningRate * PartialGrad; // now we have what the angle should be to be closer to the target, so we must set it to this. 
				FRotator CurrentRotation = Sections[Index]->GetActorRotation();
				Sections[Index]->SetActorRotation(FRotator((Axis == 1 ? Angles[Index] : CurrentRotation.Pitch),
					(Axis == 2 ? Angles[Index] : CurrentRotation.Yaw), (Axis == 0 ? Angles[Index] : CurrentRotation.Roll))); // Update the FRotators. 

				if (bRunIKOnce) {// for debug printing
					FRotator AlteredRotation = Sections[Index]->GetActorRotation();
					UE_LOG(LogTemp, Warning, TEXT("[%i],	Cur before alteration: %s,	rot after alteration: %s"), Index, *CurrentRotation.ToString(), *AlteredRotation.ToString())
						UE_LOG(LogTemp, Warning, TEXT("Original angle: %f,	altered angle: %f"), PreservedAngle, Angles[Index])
				}
			}
	}
	if (bDebugLines) {
		DrawDebugLine(GetWorld(), FindEndLocation(), Target, FColor::Red);
		DrawDebugLine(GetWorld(), GetActorLocation(), Target, FColor::Green);
	}
	return false;
}

float ATentacleBase::GetPreviousSectionAngle(int index, int axis) {
	FRotator PrevRotation;
	if (index == 0)
		PrevRotation = GetActorRotation();
	else
		PrevRotation = Sections[index - 1]->GetActorRotation();
	if (axis == 0)
		return PrevRotation.Roll;
	if (axis == 1)
		return PrevRotation.Pitch;
	if (axis == 2)
		return PrevRotation.Yaw;
	return 0.0f; // should never reach here
}

void ATentacleBase::CalculatePoints() { // A debug function that prints the location of sections, their ends, the end effector and the distance from target calculated in two ways. 
	if (Sections.Num() > 0) {
		FVector ActorLoc = GetActorLocation();// You need to put a vector into a variable before it can be printed :(
		UE_LOG(LogTemp, Warning, TEXT("TBase location:	 %s"), *ActorLoc.ToString())
			for (int16 i = 0; i < Sections.Num(); i++) {
				FVector SecLoc = Sections[i]->GetActorLocation();
				FVector SecEnd = Sections[i]->FindSectionEnd();
				UE_LOG(LogTemp, Warning, TEXT("Section[%i] location: %s		and end: %s"), i, *SecLoc.ToString(), *SecEnd.ToString())
			}
		FVector EndLoc = FindEndLocation();
		UE_LOG(LogTemp, Warning, TEXT("End effector location: %s"), *EndLoc.ToString())
			float disToTarget = DistanceFromTarget(TargetActor->GetActorLocation(), GetAngles(0), 0);
		UE_LOG(LogTemp, Warning, TEXT("According to DistanceFromTarget() the error is: %f,	and according to FVec.Dist it is: %f"), disToTarget, FVector::Dist(TargetActor->GetActorLocation(), FindEndLocation()))
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Cannot calculate points, Sections is empty!"))
}

// The type of interpolation these two functions use is important. 
// I will start with a lerp, but I want to try something with a steep dropoff too. 
void ATentacleBase::UpdateSamplingDistance() {
	float Ratio = FMath::Clamp((FVector::Dist(TargetActor->GetActorLocation(), FindEndLocation()) - MinDynamismRange) / (MaxDynamismRange - MinDynamismRange), 0.001f, 1.0f);
	DynamicSamplingDistance = FMath::Lerp(MinSample, MaxSample, Ratio);
	if (bRunIKOnce)
		UE_LOG(LogTemp, Warning, TEXT("Updating Sample, Ratio: %f,	Sampling Distance: %f"), Ratio, DynamicSamplingDistance)
}
// If they are to use different interpolations, this should drop off slower, so as to maintain some more speed. 
void ATentacleBase::UpdateLearningRate() {
	float Ratio = FMath::Clamp((FVector::Dist(TargetActor->GetActorLocation(), FindEndLocation()) - MinDynamismRange) / (MaxDynamismRange - MinDynamismRange), 0.001f, 1.0f);
	DynamicLearningRate = FMath::Lerp(MinLearningRate, MaxLearningRate, Ratio);
	if (bRunIKOnce)
		UE_LOG(LogTemp, Warning, TEXT("Updating LearnR, Ratio: %f,	Learning Rate: %f"), Ratio, DynamicLearningRate)
}

bool ATentacleBase::ShouldTickIfViewportsOnly() const {
	return true;
}