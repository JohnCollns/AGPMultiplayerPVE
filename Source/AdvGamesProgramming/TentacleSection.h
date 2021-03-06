// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"
#include "TentacleBase.h"
#include "TentacleSection.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ATentacleSection : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATentacleSection();
	UPROPERTY()
	float Length;
	float Thickness;
	UPROPERTY()
	FColor BaseColour;
	UPROPERTY()
	FColor TipColour;
	UPROPERTY(BlueprintReadOnly)
	ATentacleBase* Base;
	USceneComponent* SceneComponent;

	void GenerateSection(int16 ID);
	void GenerateSection(int16 ID, float TaperedThickness);
	//void AttachChild(ATentacleSection* Child);

	FVector FindSectionEnd();
	FVector CalculateEndAtAngle(float Angle, int Axis);
	FVector CalculateEndFromPoint(FVector Start, float Angle, int Axis);

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult);
	UFUNCTION()
	void HitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UMaterial* MaterialObject;
	UMaterial* MatInstance;
	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* MatInstanceDynamic;
	UMaterialInstanceConstant* ConstMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	float EffectiveLength;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
