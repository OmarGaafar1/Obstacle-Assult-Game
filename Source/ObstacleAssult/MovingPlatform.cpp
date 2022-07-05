// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Configures Moved Distance: %f") , MovedDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	

}


void AMovingPlatform::MovePlatform(float DeltaTime){


	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
		 float DistanceMoved = FVector::Dist(StartLocation , CurrentLocation);
	if(DistanceMoved > MovedDistance)
	{
		float OverShoot = DistanceMoved - MovedDistance ; 
		FString Name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s OverShoot =  %f"), *Name ,OverShoot);
		 FVector MovedDirection = PlatformVelocity.GetSafeNormal();
		 StartLocation += (MovedDirection*MovedDistance);
		 SetActorLocation(StartLocation);
		 PlatformVelocity = -PlatformVelocity;

	}
}


void AMovingPlatform::RotatePlatform(float DeltaTime)
{

	AddActorLocalRotation(RotationalVelocity * DeltaTime);
}

