// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVGAMESPROGRAMMING_WeaponFiringType_generated_h
#error "WeaponFiringType.generated.h already included, missing '#pragma once' in WeaponFiringType.h"
#endif
#define ADVGAMESPROGRAMMING_WeaponFiringType_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Week11Solution_Source_AdvGamesProgramming_WeaponFiringType_h


#define FOREACH_ENUM_EWEAPONFIRINGTYPE(op) \
	op(EWeaponFiringType::SINGLE_SHOT) \
	op(EWeaponFiringType::TRIPLE_SHOT) \
	op(EWeaponFiringType::AUTOMATIC) 

enum class EWeaponFiringType : uint8;
template<> ADVGAMESPROGRAMMING_API UEnum* StaticEnum<EWeaponFiringType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
