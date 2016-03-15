// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GrabComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIVE_API UGrabComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	AActor* Owner;
	APlayerController* Player;

private:
	float Reach = 100.f;

	void SetupPhysicsComponent();
	void SetupInputComponent();

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* Input = nullptr;

	void Grab(); // raycast and grab
	void Release();

	const FHitResult GetFirstPhysicsBodyInReach();
	FVector GetLineTraceStart();
	FVector GetLineTraceEnd();
		
	
};
