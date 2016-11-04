// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MaterialChangerVisual.generated.h"

class UMaterialChangerComponent;

UCLASS()
class AMaterialChangerVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaterialChangerVisual(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category="Changer")
	void ApplyMaterialOnOwner();

	UPROPERTY(BlueprintReadWrite, Category = "Changer")
	UMaterialChangerComponent * MaterialChangerComponentOwner;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Changer")
	UStaticMeshComponent * ChangerVisual;

	UPROPERTY(BlueprintReadOnly, Category = "Changer")
	int32 MaterialDataIDX = 0;
};
