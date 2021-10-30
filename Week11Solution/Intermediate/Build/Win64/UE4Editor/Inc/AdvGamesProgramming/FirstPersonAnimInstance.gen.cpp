// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/FirstPersonAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFirstPersonAnimInstance() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_UFirstPersonAnimInstance_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_UFirstPersonAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	void UFirstPersonAnimInstance::StaticRegisterNativesUFirstPersonAnimInstance()
	{
	}
	UClass* Z_Construct_UClass_UFirstPersonAnimInstance_NoRegister()
	{
		return UFirstPersonAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UFirstPersonAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[];
#endif
		static void NewProp_bIsSprinting_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFirstPersonAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstPersonAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "FirstPersonAnimInstance.h" },
		{ "ModuleRelativePath", "FirstPersonAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting_MetaData[] = {
		{ "Category", "FirstPersonAnimInstance" },
		{ "ModuleRelativePath", "FirstPersonAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting_SetBit(void* Obj)
	{
		((UFirstPersonAnimInstance*)Obj)->bIsSprinting = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting = { "bIsSprinting", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFirstPersonAnimInstance), &Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFirstPersonAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFirstPersonAnimInstance_Statics::NewProp_bIsSprinting,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFirstPersonAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFirstPersonAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFirstPersonAnimInstance_Statics::ClassParams = {
		&UFirstPersonAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFirstPersonAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFirstPersonAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UFirstPersonAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstPersonAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFirstPersonAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFirstPersonAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFirstPersonAnimInstance, 1271288358);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<UFirstPersonAnimInstance>()
	{
		return UFirstPersonAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFirstPersonAnimInstance(Z_Construct_UClass_UFirstPersonAnimInstance, &UFirstPersonAnimInstance::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("UFirstPersonAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFirstPersonAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
