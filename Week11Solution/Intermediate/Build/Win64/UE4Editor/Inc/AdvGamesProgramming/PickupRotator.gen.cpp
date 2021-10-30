// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/PickupRotator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickupRotator() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_UPickupRotator_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_UPickupRotator();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	void UPickupRotator::StaticRegisterNativesUPickupRotator()
	{
	}
	UClass* Z_Construct_UClass_UPickupRotator_NoRegister()
	{
		return UPickupRotator::StaticClass();
	}
	struct Z_Construct_UClass_UPickupRotator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPickupRotator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPickupRotator_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PickupRotator.h" },
		{ "ModuleRelativePath", "PickupRotator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPickupRotator_Statics::NewProp_RotSpeed_MetaData[] = {
		{ "Category", "PickupRotator" },
		{ "ModuleRelativePath", "PickupRotator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPickupRotator_Statics::NewProp_RotSpeed = { "RotSpeed", nullptr, (EPropertyFlags)0x0040000000000801, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPickupRotator, RotSpeed), METADATA_PARAMS(Z_Construct_UClass_UPickupRotator_Statics::NewProp_RotSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPickupRotator_Statics::NewProp_RotSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPickupRotator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPickupRotator_Statics::NewProp_RotSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPickupRotator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPickupRotator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPickupRotator_Statics::ClassParams = {
		&UPickupRotator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPickupRotator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPickupRotator_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPickupRotator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPickupRotator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPickupRotator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPickupRotator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPickupRotator, 1392944971);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<UPickupRotator>()
	{
		return UPickupRotator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPickupRotator(Z_Construct_UClass_UPickupRotator, &UPickupRotator::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("UPickupRotator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPickupRotator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
