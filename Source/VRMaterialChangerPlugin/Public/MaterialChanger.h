// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MaterialChangerVisual.h"
#include "MaterialChanger.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(MaterialChangerLog, Log, All);

USTRUCT(Blueprintable)
struct FMaterialToChangeData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface * MaterialInterface;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaterialElementIndex;
};

UCLASS()
class AMaterialChanger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaterialChanger();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

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

private:
	TArray<AActor *> Visuals;
};
