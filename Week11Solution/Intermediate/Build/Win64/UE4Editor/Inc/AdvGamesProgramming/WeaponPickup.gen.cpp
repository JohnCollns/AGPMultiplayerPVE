// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/WeaponPickup.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponPickup() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UEnum* Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AWeaponPickup_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AWeaponPickup();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_APickup();
	ADVGAMESPROGRAMMING_API UFunction* Z_Construct_UFunction_AWeaponPickup_OnGenerate();
	ADVGAMESPROGRAMMING_API UFunction* Z_Construct_UFunction_AWeaponPickup_OnPickup();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static UEnum* EWeaponPickupRarity_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity, Z_Construct_UPackage__Script_AdvGamesProgramming(), TEXT("EWeaponPickupRarity"));
		}
		return Singleton;
	}
	template<> ADVGAMESPROGRAMMING_API UEnum* StaticEnum<EWeaponPickupRarity>()
	{
		return EWeaponPickupRarity_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EWeaponPickupRarity(EWeaponPickupRarity_StaticEnum, TEXT("/Script/AdvGamesProgramming"), TEXT("EWeaponPickupRarity"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity_Hash() { return 4146164991U; }
	UEnum* Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AdvGamesProgramming();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EWeaponPickupRarity"), 0, Get_Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EWeaponPickupRarity::LEGENDARY", (int64)EWeaponPickupRarity::LEGENDARY },
				{ "EWeaponPickupRarity::MASTER", (int64)EWeaponPickupRarity::MASTER },
				{ "EWeaponPickupRarity::RARE", (int64)EWeaponPickupRarity::RARE },
				{ "EWeaponPickupRarity::COMMON", (int64)EWeaponPickupRarity::COMMON },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "COMMON.Name", "EWeaponPickupRarity::COMMON" },
				{ "LEGENDARY.Name", "EWeaponPickupRarity::LEGENDARY" },
				{ "MASTER.Name", "EWeaponPickupRarity::MASTER" },
				{ "ModuleRelativePath", "WeaponPickup.h" },
				{ "RARE.Name", "EWeaponPickupRarity::RARE" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
				nullptr,
				"EWeaponPickupRarity",
				"EWeaponPickupRarity",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_AWeaponPickup_OnPickup = FName(TEXT("OnPickup"));
	void AWeaponPickup::OnPickup(AActor* ActorThatPickedUp)
	{
		WeaponPickup_eventOnPickup_Parms Parms;
		Parms.ActorThatPickedUp=ActorThatPickedUp;
		ProcessEvent(FindFunctionChecked(NAME_AWeaponPickup_OnPickup),&Parms);
	}
	void AWeaponPickup::StaticRegisterNativesAWeaponPickup()
	{
		UClass* Class = AWeaponPickup::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnGenerate", &AWeaponPickup::execOnGenerate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWeaponPickup, nullptr, "OnGenerate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWeaponPickup_OnGenerate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWeaponPickup_OnGenerate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorThatPickedUp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::NewProp_ActorThatPickedUp = { "ActorThatPickedUp", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WeaponPickup_eventOnPickup_Parms, ActorThatPickedUp), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::NewProp_ActorThatPickedUp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWeaponPickup, nullptr, "OnPickup", nullptr, nullptr, sizeof(WeaponPickup_eventOnPickup_Parms), Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWeaponPickup_OnPickup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWeaponPickup_OnPickup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AWeaponPickup_NoRegister()
	{
		return AWeaponPickup::StaticClass();
	}
	struct Z_Construct_UClass_AWeaponPickup_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponAccuracy_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_WeaponAccuracy;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MagazineSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MagazineSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MuzzleVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BulletDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BulletDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rarity_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Rarity;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWeaponPickup_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APickup,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AWeaponPickup_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWeaponPickup_OnGenerate, "OnGenerate" }, // 4227977188
		{ &Z_Construct_UFunction_AWeaponPickup_OnPickup, "OnPickup" }, // 2677814582
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WeaponPickup.h" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::NewProp_WeaponAccuracy_MetaData[] = {
		{ "Category", "WeaponPickup" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_WeaponAccuracy = { "WeaponAccuracy", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponPickup, WeaponAccuracy), METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_WeaponAccuracy_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_WeaponAccuracy_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MagazineSize_MetaData[] = {
		{ "Category", "WeaponPickup" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MagazineSize = { "MagazineSize", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponPickup, MagazineSize), METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MagazineSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MagazineSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MuzzleVelocity_MetaData[] = {
		{ "Category", "WeaponPickup" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MuzzleVelocity = { "MuzzleVelocity", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponPickup, MuzzleVelocity), METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MuzzleVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MuzzleVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::NewProp_BulletDamage_MetaData[] = {
		{ "Category", "WeaponPickup" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_BulletDamage = { "BulletDamage", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponPickup, BulletDamage), METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_BulletDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_BulletDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity_MetaData[] = {
		{ "Category", "WeaponPickup" },
		{ "ModuleRelativePath", "WeaponPickup.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWeaponPickup, Rarity), Z_Construct_UEnum_AdvGamesProgramming_EWeaponPickupRarity, METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWeaponPickup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_WeaponAccuracy,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MagazineSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_MuzzleVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_BulletDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWeaponPickup_Statics::NewProp_Rarity_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWeaponPickup_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWeaponPickup>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWeaponPickup_Statics::ClassParams = {
		&AWeaponPickup::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWeaponPickup_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWeaponPickup_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWeaponPickup_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWeaponPickup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWeaponPickup_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWeaponPickup, 213997366);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<AWeaponPickup>()
	{
		return AWeaponPickup::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWeaponPickup(Z_Construct_UClass_AWeaponPickup, &AWeaponPickup::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("AWeaponPickup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWeaponPickup);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
