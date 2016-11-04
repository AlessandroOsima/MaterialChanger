// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMaterialChangerVisual;
class AActor;
#ifdef VRMATERIALCHANGER_MotionControllerTriggerComponent_generated_h
#error "MotionControllerTriggerComponent.generated.h already included, missing '#pragma once' in MotionControllerTriggerComponent.h"
#endif
#define VRMATERIALCHANGER_MotionControllerTriggerComponent_generated_h

#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_RPC_WRAPPERS \
	virtual void ReceiveOnApplyMaterial_Implementation(AMaterialChangerVisual* OtherVisual); \
	virtual void ReceiveOnEndTrigger_Implementation(); \
	virtual void ReceiveOnBeginTrigger_Implementation(); \
 \
	DECLARE_FUNCTION(execPlayForceFeedback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlayForceFeedback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnApplyMaterial) \
	{ \
		P_GET_OBJECT(AMaterialChangerVisual,Z_Param_OtherVisual); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnApplyMaterial_Implementation(Z_Param_OtherVisual); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnEndTrigger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnEndTrigger_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnBeginTrigger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnBeginTrigger_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnControllerEndOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnControllerEndOverlap(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnControllerBeginOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnControllerBeginOverlap(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ReceiveOnApplyMaterial_Implementation(AMaterialChangerVisual* OtherVisual); \
	virtual void ReceiveOnEndTrigger_Implementation(); \
	virtual void ReceiveOnBeginTrigger_Implementation(); \
 \
	DECLARE_FUNCTION(execPlayForceFeedback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlayForceFeedback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnApplyMaterial) \
	{ \
		P_GET_OBJECT(AMaterialChangerVisual,Z_Param_OtherVisual); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnApplyMaterial_Implementation(Z_Param_OtherVisual); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnEndTrigger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnEndTrigger_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReceiveOnBeginTrigger) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceiveOnBeginTrigger_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnControllerEndOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnControllerEndOverlap(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnControllerBeginOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnControllerBeginOverlap(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_EVENT_PARMS \
	struct MotionControllerTriggerComponent_eventReceiveOnApplyMaterial_Parms \
	{ \
		AMaterialChangerVisual* OtherVisual; \
	};


extern VRMATERIALCHANGER_API  FName VRMATERIALCHANGER_ReceiveOnApplyMaterial;
extern VRMATERIALCHANGER_API  FName VRMATERIALCHANGER_ReceiveOnBeginTrigger;
extern VRMATERIALCHANGER_API  FName VRMATERIALCHANGER_ReceiveOnEndTrigger;
#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_CALLBACK_WRAPPERS
#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUMotionControllerTriggerComponent(); \
	friend VRMATERIALCHANGER_API class UClass* Z_Construct_UClass_UMotionControllerTriggerComponent(); \
	public: \
	DECLARE_CLASS(UMotionControllerTriggerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VRMaterialChanger"), NO_API) \
	DECLARE_SERIALIZER(UMotionControllerTriggerComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_INCLASS \
	private: \
	static void StaticRegisterNativesUMotionControllerTriggerComponent(); \
	friend VRMATERIALCHANGER_API class UClass* Z_Construct_UClass_UMotionControllerTriggerComponent(); \
	public: \
	DECLARE_CLASS(UMotionControllerTriggerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VRMaterialChanger"), NO_API) \
	DECLARE_SERIALIZER(UMotionControllerTriggerComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMotionControllerTriggerComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMotionControllerTriggerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMotionControllerTriggerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMotionControllerTriggerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMotionControllerTriggerComponent(UMotionControllerTriggerComponent&&); \
	NO_API UMotionControllerTriggerComponent(const UMotionControllerTriggerComponent&); \
public:


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMotionControllerTriggerComponent(UMotionControllerTriggerComponent&&); \
	NO_API UMotionControllerTriggerComponent(const UMotionControllerTriggerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMotionControllerTriggerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMotionControllerTriggerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMotionControllerTriggerComponent)


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_10_PROLOG \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_EVENT_PARMS


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_RPC_WRAPPERS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_CALLBACK_WRAPPERS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_INCLASS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_CALLBACK_WRAPPERS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_INCLASS_NO_PURE_DECLS \
	UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UIVrTest_Plugins_VRMaterialChanger_Source_VRMaterialChangerPlugin_Public_MotionControllerTriggerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS