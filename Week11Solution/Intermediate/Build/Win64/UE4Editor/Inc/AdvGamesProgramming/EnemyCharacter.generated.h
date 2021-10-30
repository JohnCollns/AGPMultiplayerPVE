// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FAIStimulus;
struct FVector;
#ifdef ADVGAMESPROGRAMMING_EnemyCharacter_generated_h
#error "EnemyCharacter.generated.h already included, missing '#pragma once' in EnemyCharacter.h"
#endif
#define ADVGAMESPROGRAMMING_EnemyCharacter_generated_h

#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_SPARSE_DATA
#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSensePlayer) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ActorSensed); \
		P_GET_STRUCT(FAIStimulus,Z_Param_Stimulus); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SensePlayer(Z_Param_ActorSensed,Z_Param_Stimulus); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSensePlayer) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ActorSensed); \
		P_GET_STRUCT(FAIStimulus,Z_Param_Stimulus); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SensePlayer(Z_Param_ActorSensed,Z_Param_Stimulus); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_EVENT_PARMS \
	struct EnemyCharacter_eventFire_Parms \
	{ \
		FVector FireDirection; \
	};


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_CALLBACK_WRAPPERS
#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyCharacter(); \
	friend struct Z_Construct_UClass_AEnemyCharacter_Statics; \
public: \
	DECLARE_CLASS(AEnemyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(AEnemyCharacter)


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyCharacter(); \
	friend struct Z_Construct_UClass_AEnemyCharacter_Statics; \
public: \
	DECLARE_CLASS(AEnemyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(AEnemyCharacter)


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyCharacter(AEnemyCharacter&&); \
	NO_API AEnemyCharacter(const AEnemyCharacter&); \
public:


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyCharacter(AEnemyCharacter&&); \
	NO_API AEnemyCharacter(const AEnemyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyCharacter)


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_PRIVATE_PROPERTY_OFFSET
#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_18_PROLOG \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_EVENT_PARMS


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_RPC_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_CALLBACK_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_INCLASS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_CALLBACK_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_INCLASS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<class AEnemyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Week11Solution_Source_AdvGamesProgramming_EnemyCharacter_h


#define FOREACH_ENUM_AGENTSTATE(op) \
	op(AgentState::PATROL) \
	op(AgentState::ENGAGE) \
	op(AgentState::EVADE) 

enum class AgentState : uint8;
template<> ADVGAMESPROGRAMMING_API UEnum* StaticEnum<AgentState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
