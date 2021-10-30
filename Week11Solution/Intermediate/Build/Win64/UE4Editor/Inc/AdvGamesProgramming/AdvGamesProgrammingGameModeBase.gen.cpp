// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/AdvGamesProgrammingGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdvGamesProgrammingGameModeBase() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AAdvGamesProgrammingGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	void AAdvGamesProgrammingGameModeBase::StaticRegisterNativesAAdvGamesProgrammingGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_NoRegister()
	{
		return AAdvGamesProgrammingGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AdvGamesProgrammingGameModeBase.h" },
		{ "ModuleRelativePath", "AdvGamesProgrammingGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAdvGamesProgrammingGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::ClassParams = {
		&AAdvGamesProgrammingGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAdvGamesProgrammingGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAdvGamesProgrammingGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAdvGamesProgrammingGameModeBase, 4247062695);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<AAdvGamesProgrammingGameModeBase>()
	{
		return AAdvGamesProgrammingGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAdvGamesProgrammingGameModeBase(Z_Construct_UClass_AAdvGamesProgrammingGameModeBase, &AAdvGamesProgrammingGameModeBase::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("AAdvGamesProgrammingGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAdvGamesProgrammingGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
