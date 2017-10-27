// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	bool bOnServer = HasAuthority();
	


	//UE_LOG(LogTemp, Warning, TEXT("Direction: %s"), *Direction.ToString());


	if (bOnServer)
	{
		FVector Location = GetActorLocation();	 
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += Direction * DeltaTime * Velocity;
		SetActorLocation(Location, true);
	}

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	bool bOnServer = HasAuthority();

	if (bOnServer)
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

