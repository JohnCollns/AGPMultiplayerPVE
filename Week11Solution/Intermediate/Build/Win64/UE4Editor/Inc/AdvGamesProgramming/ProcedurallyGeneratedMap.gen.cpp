// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/ProcedurallyGeneratedMap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcedurallyGeneratedMap() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
	ADVGAMESPROGRAMMING_API UFunction* Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_AAIManager_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void AProcedurallyGeneratedMap::StaticRegisterNativesAProcedurallyGeneratedMap()
	{
		UClass* Class = AProcedurallyGeneratedMap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateMap", &AProcedurallyGeneratedMap::execGenerateMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProcedurallyGeneratedMap, nullptr, "GenerateMap", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister()
	{
		return AProcedurallyGeneratedMap::StaticClass();
	}
	struct Z_Construct_UClass_AProcedurallyGeneratedMap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIManager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AIManager;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRegenerateMap_MetaData[];
#endif
		static void NewProp_bRegenerateMap_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRegenerateMap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerlinRoughness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerlinRoughness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerlinScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerlinScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GridSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap, "GenerateMap" }, // 1809689899
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProcedurallyGeneratedMap.h" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_AIManager_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_AIManager = { "AIManager", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, AIManager), Z_Construct_UClass_AAIManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_AIManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_AIManager_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, Vertices), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	void Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap_SetBit(void* Obj)
	{
		((AProcedurallyGeneratedMap*)Obj)->bRegenerateMap = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap = { "bRegenerateMap", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AProcedurallyGeneratedMap), &Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap_SetBit, METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinRoughness_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinRoughness = { "PerlinRoughness", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, PerlinRoughness), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinRoughness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinRoughness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinScale_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinScale = { "PerlinScale", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, PerlinScale), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_GridSize_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, GridSize), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_GridSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_GridSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, Height), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Width_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, Width), METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Width_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Width_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, MeshComponent), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_AIManager,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_bRegenerateMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinRoughness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_PerlinScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_GridSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcedurallyGeneratedMap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::ClassParams = {
		&AProcedurallyGeneratedMap::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProcedurallyGeneratedMap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProcedurallyGeneratedMap, 3014070443);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<AProcedurallyGeneratedMap>()
	{
		return AProcedurallyGeneratedMap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProcedurallyGeneratedMap(Z_Construct_UClass_AProcedurallyGeneratedMap, &AProcedurallyGeneratedMap::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("AProcedurallyGeneratedMap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProcedurallyGeneratedMap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
