// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "MaterialChangerVisual.h"
#include "MaterialChangerComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class VRMATERIALCHANGER_API UMaterialChangerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMaterialChangerComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//The material index in the Materials array to apply to the mesh in begin play
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer")
	int32 StartMaterialIDX = 0;

	//All the material interfaces to apply to a mesh
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Changer")
	TArray<FMaterialToChangeData> Materials;

	//The actor with the static mesh we want to apply the materials to
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Changer")
	AActor * Target;

	//The visualizer to use to show the materials in the Materials array
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer")
	TSubclassOf<AMaterialChangerVisual> MaterialVisual;

	//The number to multiply to the up vector to find the visuals distances from the center of the material changer
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer Visualization")
	float UpMultiplier = 2;

	//The number to multiply to the right vector to find the visuals distances from the center of the material changer
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer Visualization")
	float SideMultiplier = 2;

	//The scale of the material visuals to spawn in the world
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer Visualization")
	FVector MaterialVisualScale;

	//Apply the material with the MaterialDataIDX in the Materials array
	UFUNCTION(BlueprintCallable, Category = "Changer")
	void ChangeOwnerMaterialWithMaterial(int MaterialDataIDX);

	void SpawnVisualsOnChanger();

private:
	TArray<AActor *> Visuals;
	
};
