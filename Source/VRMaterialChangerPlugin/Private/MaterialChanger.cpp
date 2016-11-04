// Fill out your copyright notice in the Description page of Project Settings.

#include "VRMaterialChangerPluginPrivatePCH.h"
#include "MaterialChanger.h"

DEFINE_LOG_CATEGORY(MaterialChangerLog);


// Sets default values
AMaterialChanger::AMaterialChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaterialChanger::BeginPlay()
{
	Super::BeginPlay();
	
	if (!MaterialVisual)
	{
		UE_LOG(MaterialChangerLog, Error, TEXT("You have to specify a material visualizer"));
		return;
	}

	
	FVector UpPositionFromCenter = GetActorLocation() + (GetActorUpVector() * UpMultiplier);
	FVector RightUpPositionFromCenter = UpPositionFromCenter + (GetActorRightVector() * SideMultiplier);
	FVector DirectionFromCenter = (RightUpPositionFromCenter - UpPositionFromCenter);

	//DrawDebugLine(GetWorld(), GetActorLocation(), StartPoint, FColor::Red, true, -1.f, 0, 10);
	//DrawDebugLine(GetWorld(), StartPoint, StartPosition, FColor::Blue, true, -1.f, 0, 10);

	//StartDirection.Normalize();

	FRotator IdentityRotator = FQuat::Identity.Rotator();

	float step = 360.f / Materials.Num();

	float StartAngle = 0;
	int32 Start = 0;

	for (auto & materialData : Materials)
	{
		FTransform VisualTransform;

		VisualTransform.SetLocation(UpPositionFromCenter + DirectionFromCenter.RotateAngleAxis(StartAngle, GetActorUpVector()));
		VisualTransform.SetRotation(FQuat::Identity);

		StartAngle += step;

		AMaterialChangerVisual * Visual = Cast<AMaterialChangerVisual>(GetWorld()->SpawnActor(*MaterialVisual, &VisualTransform));

		//Set owner and material idx in the spawned visual
		//Visual->MaterialChangerComponentOwner = this;
		Visual->MaterialDataIDX = Start;
		Start++;

		ensure(Visual);

		//Applying scale to transform before spawning does not scale properly
		Visual->SetActorScale3D(MaterialVisualScale);
		
		UStaticMeshComponent * StaticMeshComponent = Cast<UStaticMeshComponent>(Visual->GetComponentByClass(UStaticMeshComponent::StaticClass()));

		if (StaticMeshComponent)
		{
			StaticMeshComponent->CreateAndSetMaterialInstanceDynamicFromMaterial(0, materialData.MaterialInterface);
		}
		else
		{
			//visual without a static mesh is useless
			UE_LOG(MaterialChangerLog, Error, TEXT("Visual should have a static mesh component to apply material to"));
		}
		
		Visuals.Add(Visual);
	}

	ChangeOwnerMaterialWithMaterial(StartMaterialIDX);
}

// Called every frame
void AMaterialChanger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMaterialChanger::ChangeOwnerMaterialWithMaterial(int MaterialDataIDX)
{
	ensure(Target);

	UStaticMeshComponent * scmp = Cast<UStaticMeshComponent>(Target->GetComponentByClass(UStaticMeshComponent::StaticClass()));

	if (scmp && MaterialDataIDX >= 0 && MaterialDataIDX < Materials.Num())
	{
		scmp->CreateAndSetMaterialInstanceDynamicFromMaterial(Materials[MaterialDataIDX].MaterialElementIndex, Materials[MaterialDataIDX].MaterialInterface);
	}
}

