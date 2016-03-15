// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	//UGrabComponent* GrabComponent;

	void Grab();
	void Release();
};
