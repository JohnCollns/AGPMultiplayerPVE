// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvGamesProgramming/NavigationNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavigationNode() {}
// Cross Module References
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_ANavigationNode_NoRegister();
	ADVGAMESPROGRAMMING_API UClass* Z_Construct_UClass_ANavigationNode();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdvGamesProgramming();
// End Cross Module References
	void ANavigationNode::StaticRegisterNativesANavigationNode()
	{
	}
	UClass* Z_Construct_UClass_ANavigationNode_NoRegister()
	{
		return ANavigationNode::StaticClass();
	}
	struct Z_Construct_UClass_ANavigationNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConnectedNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ConnectedNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConnectedNodes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANavigationNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdvGamesProgramming,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavigationNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NavigationNode.h" },
		{ "ModuleRelativePath", "NavigationNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes_MetaData[] = {
		{ "Category", "ConnectedNodes" },
		{ "ModuleRelativePath", "NavigationNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes = { "ConnectedNodes", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANavigationNode, ConnectedNodes), METADATA_PARAMS(Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes_Inner = { "ConnectedNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ANavigationNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANavigationNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationNode_Statics::NewProp_ConnectedNodes_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANavigationNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANavigationNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANavigationNode_Statics::ClassParams = {
		&ANavigationNode::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANavigationNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationNode_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANavigationNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANavigationNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANavigationNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANavigationNode, 701370233);
	template<> ADVGAMESPROGRAMMING_API UClass* StaticClass<ANavigationNode>()
	{
		return ANavigationNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANavigationNode(Z_Construct_UClass_ANavigationNode, &ANavigationNode::StaticClass, TEXT("/Script/AdvGamesProgramming"), TEXT("ANavigationNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANavigationNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
