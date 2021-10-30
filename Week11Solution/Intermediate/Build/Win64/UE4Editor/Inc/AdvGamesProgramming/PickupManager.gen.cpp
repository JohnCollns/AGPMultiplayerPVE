// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/PickupManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickupManager() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APickupManager_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APickupManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	void APickupManager::StaticRegisterNativesAPickupManager()
	{
	}
	UClass* Z_Construct_UClass_APickupManager_NoRegister()
	{
		return APickupManager::StaticClass();
	}
	struct Z_Construct_UClass_APickupManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickupManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickupManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PickupManager.h" },
		{ "ModuleRelativePath", "PickupManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickupManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickupManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APickupManager_Statics::ClassParams = {
		&APickupManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APickupManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APickupManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickupManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APickupManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickupManager, 3571649995);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<APickupManager>()
	{
		return APickupManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickupManager(Z_Construct_UClass_APickupManager, &APickupManager::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("APickupManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickupManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
