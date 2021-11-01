// Fill out your copyright notice in the Description page of Project Settings.


#include "TentacleSection.h"

// Sets default values
ATentacleSection::ATentacleSection()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Length = 0.5f;
	Thickness = 0.35f;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder Mesh Component"));
	Mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (CylinderAsset.Succeeded())
	{
		Mesh->SetStaticMesh(CylinderAsset.Object);
		EffectiveLength = 100.0f; // length of the model undialated. 
		Mesh->SetWorldScale3D(FVector(Thickness, Thickness, Length));
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, Length / 2));// This will make the mesh sit above the scene component, so that the bottom of the mesh is at the scene component. 
	}

	MatInstanceDynamic = nullptr;
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> FoundMaterial(TEXT("'/Game/Materials/M_Tentacle_Inst'"));
	if (FoundMaterial.Succeeded()) {
		ConstMaterial = FoundMaterial.Object;
		Mesh->SetMaterial(0, ConstMaterial);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Could not find Material"))
}

// Called when the game starts or when spawned
void ATentacleSection::BeginPlay()
{
	Super::BeginPlay();
	if (ConstMaterial) {
		// If we have loaded the base material, create the dynamic instance. Set its values. 
		MatInstanceDynamic = UMaterialInstanceDynamic::Create(ConstMaterial, this, FName("Dynamic Material Instance"));
		if (MatInstanceDynamic) {
			MatInstanceDynamic->SetVectorParameterValue("BaseColour", BaseColour);
			MatInstanceDynamic->SetVectorParameterValue("TipColour", TipColour);
			Mesh->SetMaterial(0, MatInstanceDynamic);
		}
	}
}

FVector ATentacleSection::FindSectionEnd() {
	return GetActorLocation() + EffectiveLength * GetActorUpVector(); // Finds the end point using a worldspace normal-vector of the direction the section is pointing, the length and origin. 
}

FVector ATentacleSection::CalculateEndAtAngle(float Angle, int Axis) { // Finds the endpoint of section with an altered angle, but does not permanently change the angle. 
	// Axes 0-Roll, 1-Pitch, 2-Yaw
	FRotator CurrentRotation = GetActorRotation();
	FRotator TestRotation = FRotator((Axis == 1 ? Angle : CurrentRotation.Pitch), (Axis == 2 ? Angle : CurrentRotation.Yaw), (Axis == 0 ? Angle : CurrentRotation.Roll));//PYR
	SetActorRotation(TestRotation);
	FVector ReturnValue = FindSectionEnd();
	SetActorRotation(CurrentRotation);
	return ReturnValue;
}

FVector ATentacleSection::CalculateEndFromPoint(FVector Start, float Angle, int Axis) { // Calculates where the endpoint would be if it had a different origin and was at a different angle. 
	FRotator CurrentRotation = GetActorRotation();
	FRotator TestRotation = FRotator((Axis == 1 ? Angle : CurrentRotation.Pitch), (Axis == 2 ? Angle : CurrentRotation.Yaw), (Axis == 0 ? Angle : CurrentRotation.Roll));//PYR
	SetActorRotation(TestRotation);
	FVector ReturnValue = Start + EffectiveLength * GetActorUpVector();
	SetActorRotation(CurrentRotation);
	return ReturnValue;
}

void ATentacleSection::GenerateSection(int16 ID) {
	if (Mesh) {
		//float WorldLength = 100.0f * Length; // 100.0f is the length of the cylinder model in world units. If you are going to adjust the size you must multiply it by this amount. 
		EffectiveLength = 100.0f * Length; // 100.0f is the length of the cylinder model in world units. If you are going to adjust the size you must multiply it by this amount. 
		Mesh->SetWorldScale3D(FVector(Thickness, Thickness, Length));
		SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, EffectiveLength * ID)); // places this section above the previous
	}
}

void ATentacleSection::GenerateSection(int16 ID, float TaperedThickness) { // additional semi constructor used for tapering the tentacle. 
	GenerateSection(ID);
	if (Mesh)
		Mesh->SetWorldScale3D(FVector(TaperedThickness, TaperedThickness, Length));
}

// Called every frame
void ATentacleSection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

