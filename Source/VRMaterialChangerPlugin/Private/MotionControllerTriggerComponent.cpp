// Fill out your copyright notice in the Description page of Project Settings.

#include "VRMaterialChangerPluginPrivatePCH.h"
#include "Classes/Components/InputComponent.h"
#include "MaterialChangerVisual.h"
#include "MotionControllerTriggerComponent.h"


// Sets default values for this component's properties
UMotionControllerTriggerComponent::UMotionControllerTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMotionControllerTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	MotionControllerComponent = Cast<UMotionControllerComponent>(this->GetOwner()->GetComponentByClass(UMotionControllerComponent::StaticClass()));

	AActor * Owner = GetOwner();

	if (MotionControllerComponent)
	{
		Owner->OnActorBeginOverlap.AddDynamic(this, &UMotionControllerTriggerComponent::OnControllerBeginOverlap);
		Owner->OnActorEndOverlap.AddDynamic(this, &UMotionControllerTriggerComponent::OnControllerEndOverlap);
	}
	else
	{

	}

	if (TriggerWithActionInsideCollision)
	{
		UInputComponent * OwnerInputComponent = Owner->InputComponent;

		if (!OwnerInputComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("There is no input component on Actor %s, EnableInput should be called via blueprint"), *Owner->GetName());

			//Call enable input on the actor to get an input component
			Owner->EnableInput(*(GetWorld()->GetPlayerControllerIterator() + MotionControllerComponent->PlayerIndex));
			OwnerInputComponent = Owner->InputComponent;
			OwnerInputComponent->bBlockInput = false;
		}


		if (MotionControllerComponent->Hand == EControllerHand::Left)
		{
			FInputActionBinding& action = OwnerInputComponent->BindAction(LeftActionName, EInputEvent::IE_Pressed, this, &UMotionControllerTriggerComponent::OnMotionControllerTriggerPressed);
			action.bConsumeInput = ActionConsumesInput;
			//OwnerInputComponent->BindKey(EKeys::MotionController_Left_Trigger, IE_Pressed, this, &UMotionControllerTriggerComponent::OnMotionControllerTriggerPressed);
		}
		else
		{
			FInputActionBinding& action = OwnerInputComponent->BindAction(RightActionName, EInputEvent::IE_Pressed, this, &UMotionControllerTriggerComponent::OnMotionControllerTriggerPressed);
			action.bConsumeInput = ActionConsumesInput;
			//OwnerInputComponent->BindKey(EKeys::MotionController_Right_Trigger, IE_Pressed, this, &UMotionControllerTriggerComponent::OnMotionControllerTriggerPressed);
		}
	}
}


// Called every frame
void UMotionControllerTriggerComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...

}

void UMotionControllerTriggerComponent::OnControllerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Visual = Cast<AMaterialChangerVisual>(OtherActor);

	if (TriggerWithActionInsideCollision)
	{
		if (Visual)
		{
			bIsCollidingWithVisual = true;
			ReceiveOnBeginTrigger();
		}
	}
	else
	{
		if (Visual)
		{
			ReceiveOnBeginTrigger();
			ReceiveOnApplyMaterial(Visual);
		}
	}
}

void UMotionControllerTriggerComponent::OnControllerEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{

	if (TriggerWithActionInsideCollision)
	{
		AMaterialChangerVisual * Vs = Cast<AMaterialChangerVisual>(OtherActor);

		if (Visual && Vs && Vs == Visual)
		{
			ReceiveOnEndTrigger();
			bIsCollidingWithVisual = false;
			Visual = nullptr;
		}
	}
	else
	{
		ReceiveOnEndTrigger();
		Visual = nullptr;
	}
}

void UMotionControllerTriggerComponent::OnMotionControllerTriggerPressed()
{
	if (bIsCollidingWithVisual && Visual)
	{
		ReceiveOnApplyMaterial(Visual);
	}
}

void UMotionControllerTriggerComponent::PlayForceFeedback()
{
	APlayerController * playerController = *(GetWorld()->GetPlayerControllerIterator() + MotionControllerComponent->PlayerIndex);
	
	FLatentActionInfo info;
	info.CallbackTarget = this;
	if (MotionControllerComponent->Hand == EControllerHand::Left)
	{
		playerController->PlayDynamicForceFeedback(ForceFeedbackIntensity, ForceFeedbackDuration, true, true, false, false, EDynamicForceFeedbackAction::Start, info);
	}
	else
	{
		playerController->PlayDynamicForceFeedback(ForceFeedbackIntensity, ForceFeedbackDuration, false, false, true, true, EDynamicForceFeedbackAction::Start, info);
	}
}

void UMotionControllerTriggerComponent::ReceiveOnBeginTrigger_Implementation()
{
	PlayForceFeedback();
}

void UMotionControllerTriggerComponent::ReceiveOnEndTrigger_Implementation()
{

}

void UMotionControllerTriggerComponent::ReceiveOnApplyMaterial_Implementation(AMaterialChangerVisual * OtherVisual)
{
	OtherVisual->ApplyMaterialOnOwner();
}

