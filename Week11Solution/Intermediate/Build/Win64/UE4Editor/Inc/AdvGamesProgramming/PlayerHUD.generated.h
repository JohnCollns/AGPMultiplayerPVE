// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVGAMESPROGRAMMING_PlayerHUD_generated_h
#error "PlayerHUD.generated.h already included, missing '#pragma once' in PlayerHUD.h"
#endif
#define ADVGAMESPROGRAMMING_PlayerHUD_generated_h

#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_SPARSE_DATA
#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetAmmoText) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_RoundsRemaining); \
		P_GET_PROPERTY(UIntProperty,Z_Param_RoundsInMagazine); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAmmoText(Z_Param_RoundsRemaining,Z_Param_RoundsInMagazine); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetAmmoText) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_RoundsRemaining); \
		P_GET_PROPERTY(UIntProperty,Z_Param_RoundsInMagazine); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetAmmoText(Z_Param_RoundsRemaining,Z_Param_RoundsInMagazine); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerHUD(); \
	friend struct Z_Construct_UClass_APlayerHUD_Statics; \
public: \
	DECLARE_CLASS(APlayerHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(APlayerHUD)


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerHUD(); \
	friend struct Z_Construct_UClass_APlayerHUD_Statics; \
public: \
	DECLARE_CLASS(APlayerHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(APlayerHUD)


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerHUD(APlayerHUD&&); \
	NO_API APlayerHUD(const APlayerHUD&); \
public:


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerHUD(APlayerHUD&&); \
	NO_API APlayerHUD(const APlayerHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerHUD)


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_PRIVATE_PROPERTY_OFFSET
#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_12_PROLOG
#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_RPC_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_INCLASS \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_INCLASS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<class APlayerHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Week11Solution_Source_AdvGamesProgramming_PlayerHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
