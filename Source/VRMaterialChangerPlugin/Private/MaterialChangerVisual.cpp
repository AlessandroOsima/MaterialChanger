// Fill out your copyright notice in the Description page of Project Settings.

#include "VRMaterialChangerPluginPrivatePCH.h"
#include "MaterialChanger.h"
#include "MaterialChangerVisual.h"


// Sets default values
AMaterialChangerVisual::AMaterialChangerVisual(const class FObjectInitializer& PCIP) : Super(PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChangerVisual = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("ChangerVisual"));
}

// Called when the game starts or when spawned
void AMaterialChangerVisual::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaterialChangerVisual::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AMaterialChangerVisual::ApplyMaterialOnOwner()
{
	MaterialChangerComponentOwner->ChangeOwnerMaterialWithMaterial(MaterialDataIDX);
}

