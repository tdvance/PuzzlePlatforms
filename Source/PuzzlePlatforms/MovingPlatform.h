// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();

protected:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Velocity = 15.f;

	UPROPERTY(EditAnywhere, Category = "Movement", Meta=(MakeEditWidget=true))
	FVector TargetLocation = FVector(0.f, 0.f, 0.f);

};
