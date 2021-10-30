// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FirstPersonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ADVGAMESPROGRAMMING_API UFirstPersonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UFirstPersonAnimInstance();

public:

	UPROPERTY(BlueprintReadWrite)
	bool bIsSprinting;

};
