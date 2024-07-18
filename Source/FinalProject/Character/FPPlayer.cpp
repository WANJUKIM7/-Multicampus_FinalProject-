// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/WidgetComponent.h"
#include "UI/FPPlayerNameWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DirectionalLight.h"
#include "Actors/FP07PointLight.h"

AFPPlayer::AFPPlayer()
	: HP(100.0f)
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Nickname Widget
	Nickname = CreateDefaultSubobject<UWidgetComponent>(TEXT("Nickname"));
	Nickname->SetupAttachment(GetRootComponent());

	ConstructorHelpers::FClassFinder<UUserWidget> NicknameWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_PlayerName.WB_PlayerName_C'"));
	if (NicknameWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("NicknameWidgetClass.Succeeded"));
		Nickname->SetWidgetClass(NicknameWidgetClass.Class);
		Nickname->SetWidgetSpace(EWidgetSpace::Screen);
		Nickname->SetDrawAtDesiredSize(true);
		Nickname->SetRelativeLocation(FVector(0, 0, 100));
	}
}

void AFPPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Set Name UI
	if (UFPPlayerNameWidget* Name = Cast<UFPPlayerNameWidget>(Nickname->GetUserWidgetObject()))
	{
		FText NewName = FText::FromString(TEXT("Player"));
		Name->SetName(NewName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UI Failed"));
	}
}

void AFPPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPPlayer::SetGravityScale(float Value)
{
	GetCharacterMovement()->GravityScale = Value;
}

void AFPPlayer::SetViewReduction()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADirectionalLight::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors)
    {
        ADirectionalLight* DirLight = Cast<ADirectionalLight>(Actor);
        if (DirLight)
        {
			DirLight->SetBrightness(0.0f);			
        }
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Directional Light"));
		}
    }

	PointLight = GetWorld()->SpawnActor<AFP07PointLight>(GetCapsuleComponent()->GetComponentLocation(), GetCapsuleComponent()->GetComponentRotation());
	//PointLight->SetActorLocation(GetMesh()->GetComponentLocation());
	PointLight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}
