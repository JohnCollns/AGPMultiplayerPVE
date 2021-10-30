// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/WeaponFiringType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponFiringType() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UEnum* Z_Construct_UEnum_AdvGamesProgramming_EWeaponFiringType();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	static UEnum* EWeaponFiringType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AdvGamesProgramming_EWeaponFiringType, Z_Construct_UPackage__Script_AdvGamesProgramming(), TEXT("EWeaponFiringType"));
		}
		return Singleton;
	}
	template<> ADVGAMESPROGRAMMING_API UEnum* StaticEnum<EWeaponFiringType>()
	{
		return EWeaponFiringType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EWeaponFiringType(EWeaponFiringType_StaticEnum, TEXT("/Script/AdvGamesProgramming"), TEXT("EWeaponFiringType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AdvGamesProgramming_EWeaponFiringType_Hash() { return 3716006961U; }
	UEnum* Z_Construct_UEnum_AdvGamesProgramming_EWeaponFiringType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AdvGamesProgramming();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EWeaponFiringType"), 0, Get_Z_Construct_UEnum_AdvGamesProgramming_EWeaponFiringType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EWeaponFiringType::SINGLE_SHOT", (int64)EWeaponFiringType::SINGLE_SHOT },
				{ "EWeaponFiringType::TRIPLE_SHOT", (int64)EWeaponFiringType::TRIPLE_SHOT },
				{ "EWeaponFiringType::AUTOMATIC", (int64)EWeaponFiringType::AUTOMATIC },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AUTOMATIC.Name", "EWeaponFiringType::AUTOMATIC" },
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "WeaponFiringType.h" },
				{ "SINGLE_SHOT.Name", "EWeaponFiringType::SINGLE_SHOT" },
				{ "TRIPLE_SHOT.Name", "EWeaponFiringType::TRIPLE_SHOT" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
				nullptr,
				"EWeaponFiringType",
				"EWeaponFiringType",
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
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
