// Fill out your copyright notice in the Description page of Project Settings.

#include "vive.h"
#include "ViveCharacter.h"


// Sets default values
AViveCharacter::AViveCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	/// Get Grab component
	/*GrabComponent = CreateDefaultSubobject<UActorComponent>(TEXT("GrabComponent"));
	if (GrabComponent) {
		UE_LOG(LogTemp, Warning, TEXT("Got grabber"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Jack shit"));
	}*/
}

// Called when the game starts or when spawned
void AViveCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AViveCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AViveCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AViveCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AViveCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	InputComponent->BindAction("Grab", IE_Pressed, this, &AViveCharacter::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &AViveCharacter::Release);
}

void AViveCharacter::MoveForward(float Val) {
	if (Val != 0.f) {
		AddMovementInput(GetActorForwardVector(), Val);
	}
}

void AViveCharacter::MoveRight(float Val) {
	if (Val != 0.f) {
		AddMovementInput(GetActorRightVector(), Val);
	}
}

void AViveCharacter::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
	//GrabComponent->
}

void AViveCharacter::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Grab released"));
}

