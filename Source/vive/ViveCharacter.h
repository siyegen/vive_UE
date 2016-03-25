// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GrabComponent.h"
#include "GameFramework/Character.h"
#include "ViveCharacter.generated.h"

UCLASS()
class VIVE_API AViveCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AViveCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
protected:
	void MoveForward(float Val);
	void MoveRight(float Val);

	UGrabComponent* GrabComponent = nullptr;

	void Use();
	void UseRelease();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Testing)
	FString LookingAt = ""; // Temp Var to test HUD
private:
	FCollisionQueryParams TraceParams = nullptr;
	UPROPERTY(EditAnywhere)
	float InteractDist = 150.f;
	UPROPERTY(EditAnywhere)
	bool DrawDebug = false;

	const FHitResult GetFirstInteractWithInReach();
};
