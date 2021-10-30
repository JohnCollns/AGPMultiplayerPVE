// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVGAMESPROGRAMMING_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define ADVGAMESPROGRAMMING_PlayerCharacter_generated_h

#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_SPARSE_DATA
#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_RPC_WRAPPERS \
	virtual void SetPlayerHUDVisibility_Implementation(bool bHUDVisible); \
	virtual void ServerSprintEnd_Implementation(); \
	virtual void ServerSprintStart_Implementation(); \
 \
	DECLARE_FUNCTION(execSetPlayerHUDVisibility) \
	{ \
		P_GET_UBOOL(Z_Param_bHUDVisible); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPlayerHUDVisibility_Implementation(Z_Param_bHUDVisible); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSprintEnd) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ServerSprintEnd_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSprintStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ServerSprintStart_Implementation(); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void SetPlayerHUDVisibility_Implementation(bool bHUDVisible); \
	virtual void ServerSprintEnd_Implementation(); \
	virtual void ServerSprintStart_Implementation(); \
 \
	DECLARE_FUNCTION(execSetPlayerHUDVisibility) \
	{ \
		P_GET_UBOOL(Z_Param_bHUDVisible); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPlayerHUDVisibility_Implementation(Z_Param_bHUDVisible); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSprintEnd) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ServerSprintEnd_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSprintStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ServerSprintStart_Implementation(); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_EVENT_PARMS \
	struct PlayerCharacter_eventSetPlayerHUDVisibility_Parms \
	{ \
		bool bHUDVisible; \
	};


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_CALLBACK_WRAPPERS
#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public:


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter)


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_PRIVATE_PROPERTY_OFFSET
#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_10_PROLOG \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_EVENT_PARMS


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_RPC_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_CALLBACK_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_INCLASS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_CALLBACK_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_INCLASS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Week11Solution_Source_AdvGamesProgramming_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
