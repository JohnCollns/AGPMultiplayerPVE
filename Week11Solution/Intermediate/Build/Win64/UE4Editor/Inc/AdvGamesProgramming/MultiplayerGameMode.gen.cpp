// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/MultiplayerGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerGameMode() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AMultiplayerGameMode_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AMultiplayerGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
	ADVGAMESPROGRAMMING_API UFunction* Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APickup_NoRegister();
// End Cross Module References
	void AMultiplayerGameMode::StaticRegisterNativesAMultiplayerGameMode()
	{
		UClass* Class = AMultiplayerGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TriggerRespawn", &AMultiplayerGameMode::execTriggerRespawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics
	{
		struct MultiplayerGameMode_eventTriggerRespawn_Parms
		{
			AController* Controller;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiplayerGameMode_eventTriggerRespawn_Parms, Controller), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::NewProp_Controller,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MultiplayerGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMultiplayerGameMode, nullptr, "TriggerRespawn", nullptr, nullptr, sizeof(MultiplayerGameMode_eventTriggerRespawn_Parms), Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMultiplayerGameMode_NoRegister()
	{
		return AMultiplayerGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMultiplayerGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponPickupClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WeaponPickupClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMultiplayerGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMultiplayerGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMultiplayerGameMode_TriggerRespawn, "TriggerRespawn" }, // 4230941545
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMultiplayerGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MultiplayerGameMode.h" },
		{ "ModuleRelativePath", "MultiplayerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMultiplayerGameMode_Statics::NewProp_WeaponPickupClass_MetaData[] = {
		{ "Category", "MultiplayerGameMode" },
		{ "ModuleRelativePath", "MultiplayerGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMultiplayerGameMode_Statics::NewProp_WeaponPickupClass = { "WeaponPickupClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMultiplayerGameMode, WeaponPickupClass), Z_Construct_UClass_APickup_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMultiplayerGameMode_Statics::NewProp_WeaponPickupClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMultiplayerGameMode_Statics::NewProp_WeaponPickupClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMultiplayerGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultiplayerGameMode_Statics::NewProp_WeaponPickupClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMultiplayerGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMultiplayerGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMultiplayerGameMode_Statics::ClassParams = {
		&AMultiplayerGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMultiplayerGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMultiplayerGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMultiplayerGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMultiplayerGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMultiplayerGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMultiplayerGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMultiplayerGameMode, 2154282172);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<AMultiplayerGameMode>()
	{
		return AMultiplayerGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMultiplayerGameMode(Z_Construct_UClass_AMultiplayerGameMode, &AMultiplayerGameMode::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("AMultiplayerGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMultiplayerGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
