// Fill out your copyright notice in the Description page of Project Settings.

#include "vive.h"
#include "ViveCharacter.h"

#define ECC_INTERACT_WITH ECC_GameTraceChannel1 
// Sets default values
AViveCharacter::AViveCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	/// Get Grab component
	GrabComponent = CreateDefaultSubobject<UGrabComponent>(TEXT("GrabComponent"));
	if (GrabComponent) {
		UE_LOG(LogTemp, Warning, TEXT("Got grabber"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Jack shit"));
	}
	TraceParams = FCollisionQueryParams(FName(TEXT("")), false, this);
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
	FVector PlayerLocation;
	FRotator PlayerRotator;
	FHitResult LineHit;

	GetActorEyesViewPoint(PlayerLocation, PlayerRotator);
	FVector EndTrace = PlayerLocation + PlayerRotator.Vector() * 150.f;
	DrawDebugLine(GetWorld(), PlayerLocation, EndTrace, FColor(255, 0, 0), false, 0.f, 0.f, 10.f);
	bool DidHit = GetWorld()->LineTraceSingleByChannel(
		LineHit,
		PlayerLocation,
		EndTrace,
		ECollisionChannel::ECC_INTERACT_WITH,
		TraceParams,
		FCollisionResponseParams(ECollisionResponse::ECR_Block)
	);
	if (DidHit) {
		UE_LOG(LogTemp, Warning, TEXT("%s hit!"), *LineHit.GetActor()->GetName());
	}
}

// Called to bind functionality to input
void AViveCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AViveCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AViveCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	InputComponent->BindAction("Use", IE_Pressed, this, &AViveCharacter::Use);
	InputComponent->BindAction("Use", IE_Released, this, &AViveCharacter::UseRelease);
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

// High level catch for "using", should determine what kind of interaction
// and delegate to the proper subsystem
void AViveCharacter::Use() {
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
	// Project out and see what is there, then determine what to do with it.
	// Perhaps project on tick and then have it here? Switch on enum
	// ex: Physics, Press (default), Hack, 
	GrabComponent->Grab(); // Temp call
}

void AViveCharacter::UseRelease() {
	UE_LOG(LogTemp, Warning, TEXT("Grab released"));
}

