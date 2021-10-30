// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/PlayerHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerHUD() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APlayerHUD_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APlayerHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
	ADVGAMESPROGRAMMING_API UFunction* Z_Construct_UFunction_APlayerHUD_SetAmmoText();
// End Cross Module References
	void APlayerHUD::StaticRegisterNativesAPlayerHUD()
	{
		UClass* Class = APlayerHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetAmmoText", &APlayerHUD::execSetAmmoText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics
	{
		struct PlayerHUD_eventSetAmmoText_Parms
		{
			int32 RoundsRemaining;
			int32 RoundsInMagazine;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RoundsInMagazine;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RoundsRemaining;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::NewProp_RoundsInMagazine = { "RoundsInMagazine", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerHUD_eventSetAmmoText_Parms, RoundsInMagazine), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::NewProp_RoundsRemaining = { "RoundsRemaining", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerHUD_eventSetAmmoText_Parms, RoundsRemaining), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::NewProp_RoundsInMagazine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::NewProp_RoundsRemaining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PlayerHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerHUD, nullptr, "SetAmmoText", nullptr, nullptr, sizeof(PlayerHUD_eventSetAmmoText_Parms), Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APlayerHUD_SetAmmoText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APlayerHUD_SetAmmoText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APlayerHUD_NoRegister()
	{
		return APlayerHUD::StaticClass();
	}
	struct Z_Construct_UClass_APlayerHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APlayerHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerHUD_SetAmmoText, "SetAmmoText" }, // 4007880394
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "PlayerHUD.h" },
		{ "ModuleRelativePath", "PlayerHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayerHUD_Statics::ClassParams = {
		&APlayerHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APlayerHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayerHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayerHUD, 1641440708);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<APlayerHUD>()
	{
		return APlayerHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerHUD(Z_Construct_UClass_APlayerHUD, &APlayerHUD::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("APlayerHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
