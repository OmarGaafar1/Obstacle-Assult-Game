// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnywhere , Category="Moving ")
	FVector PlatformVelocity = FVector(100,0,0);

	FVector StartLocation;

	UPROPERTY(EditAnywhere , Category="Moving ")
	float MovedDistance = 100 ; 
	
UPROPERTY(EditAnywhere , Category = "Rotation")
 FRotator RotationalVelocity ;// 0 0 0

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

};
