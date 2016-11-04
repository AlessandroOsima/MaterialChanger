// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MotionControllerComponent.h"
#include "Components/ActorComponent.h"
#include "MotionControllerTriggerComponent.generated.h"


UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VRMATERIALCHANGER_API UMotionControllerTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotionControllerTriggerComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	UFUNCTION()
	void OnControllerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnControllerEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	void OnMotionControllerTriggerPressed();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	bool TriggerWithActionInsideCollision = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	FName LeftActionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	FName RightActionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	bool ActionConsumesInput = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	float ForceFeedbackIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	float ForceFeedbackDuration;

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "OnBeginTrigger"), Category = "Material Changer")
	void ReceiveOnBeginTrigger();

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "OnEndTrigger"), Category = "Material Changer")
	void ReceiveOnEndTrigger();

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "OnApplyMaterial"), Category = "Material Changer")
	void ReceiveOnApplyMaterial(AMaterialChangerVisual * OtherVisual);

	UFUNCTION(BlueprintCallable, Category = "Material Changer")
	void PlayForceFeedback();

private:
	UMotionControllerComponent * MotionControllerComponent = nullptr;

	bool bIsCollidingWithVisual = false;
	AMaterialChangerVisual * Visual = nullptr;
};
