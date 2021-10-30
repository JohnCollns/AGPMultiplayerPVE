// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVGAMESPROGRAMMING_MainGameInstance_generated_h
#error "MainGameInstance.generated.h already included, missing '#pragma once' in MainGameInstance.h"
#endif
#define ADVGAMESPROGRAMMING_MainGameInstance_generated_h

#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_SPARSE_DATA
#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadMenu(); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadMenu(); \
		P_NATIVE_END; \
	}


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMainGameInstance(); \
	friend struct Z_Construct_UClass_UMainGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMainGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(UMainGameInstance)


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUMainGameInstance(); \
	friend struct Z_Construct_UClass_UMainGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMainGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/AdvGamesProgramming"), NO_API) \
	DECLARE_SERIALIZER(UMainGameInstance)


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainGameInstance(UMainGameInstance&&); \
	NO_API UMainGameInstance(const UMainGameInstance&); \
public:


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainGameInstance(UMainGameInstance&&); \
	NO_API UMainGameInstance(const UMainGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainGameInstance)


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_PRIVATE_PROPERTY_OFFSET
#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_16_PROLOG
#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_RPC_WRAPPERS \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_INCLASS \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_SPARSE_DATA \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_INCLASS_NO_PURE_DECLS \
	Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<class UMainGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Week11Solution_Source_AdvGamesProgramming_MainGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
