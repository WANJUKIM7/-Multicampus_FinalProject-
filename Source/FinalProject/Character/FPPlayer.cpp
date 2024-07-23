// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/WidgetComponent.h"
#include "UI/FPPlayerNameWidget.h"
#include "UI/FPPlayerHPWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DirectionalLight.h"
#include "Actors/FP07PointLight.h"
#include "Components/SpotLightComponent.h"

AFPPlayer::AFPPlayer()
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
	NicknameUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Nickname"));
	NicknameUI->SetupAttachment(GetRootComponent());

	ConstructorHelpers::FClassFinder<UUserWidget> NicknameWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_PlayerName.WB_PlayerName_C'"));
	if (NicknameWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("NicknameWidgetClass.Succeeded"));
		NicknameUI->SetWidgetClass(NicknameWidgetClass.Class);
		NicknameUI->SetWidgetSpace(EWidgetSpace::Screen);
		NicknameUI->SetDrawAtDesiredSize(true);
		NicknameUI->SetRelativeLocation(FVector(0, 0, 100));
	}

	// HP Widget
    ConstructorHelpers::FClassFinder<UUserWidget> PlayerHPWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_PlayerHP.WB_PlayerHP_C'"));
    if (PlayerHPWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("PlayerHPWidgetClass.Succeeded"));
        PlayerHPWidgetClassReference = PlayerHPWidgetClass.Class;
	}

	// Lv01 SpotLight
	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SpotLight->SetupAttachment(GetRootComponent());
	SpotLight->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpotLight->SetRelativeLocation(FVector(0.0f, 0.0f, 320.0f));
	SpotLight->SetIntensity(100000.0f);
	SpotLight->SetOuterConeAngle(22.0f);
	SpotLight->SetVisibility(false);
}

void AFPPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Set Name UI
	if (UFPPlayerNameWidget* Name = Cast<UFPPlayerNameWidget>(NicknameUI->GetUserWidgetObject()))
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

	SetSpotLight();
	//PointLight = GetWorld()->SpawnActor<AFP07PointLight>(GetCapsuleComponent()->GetComponentLocation(), GetCapsuleComponent()->GetComponentRotation());
	////PointLight->SetActorLocation(GetMesh()->GetComponentLocation());
	//PointLight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void AFPPlayer::SetViewDefault()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADirectionalLight::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors)
    {
        ADirectionalLight* DirLight = Cast<ADirectionalLight>(Actor);
        if (DirLight)
        {
			DirLight->SetBrightness(3.0f);			
        }
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Directional Light"));
		}
    }

	if (PointLight)
	{
		PointLight->Destroy();
	}
	if (SpotLight)
	{
		SpotLight->SetVisibility(false);
	}
}

void AFPPlayer::SetSpotLight()
{
	SpotLight->SetVisibility(true);
	UE_LOG(LogTemp, Log, TEXT("SetSpotLight"));
}

void AFPPlayer::SetMovementVelocity(float Value)
{
	GetCharacterMovement()->MaxWalkSpeed = 800.0f;
}

void AFPPlayer::SpawnPlayerHPUI()
{
	TObjectPtr<UWidgetComponent> UI = NewObject<UWidgetComponent>(this, UWidgetComponent::StaticClass());
    UI->SetWidgetClass(PlayerHPWidgetClassReference);
    UI->RegisterComponent();

    if (PlayerHPUI = Cast<UFPPlayerHPWidget>(UI->GetUserWidgetObject()))
	{
        PlayerHPUI->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerHP UI Failed"));
	}
}

void AFPPlayer::UpdateHPUI(float NewHP)
{
	PlayerHPUI->UpdateHP(NewHP);
}

void AFPPlayer::SetHP(float NewHP)
{
	HP = NewHP;
	if (HP <= 0.0f)
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
        if (PlayerController)
        {
            PlayerController->DisableInput(PlayerController);
        }

        FVector LaunchVelocity = FVector(1000.0f, 1000.0f, 600.0f);
        LaunchCharacter(LaunchVelocity, true, true);
		GetCharacterMovement()->AirControl = 0.0f;
        GetCharacterMovement()->BrakingDecelerationFlying = 0.0f;
		GetCharacterMovement()->BrakingDecelerationFalling = 0.0f;
		SetGravityScale(0.4f);
	}
}

void AFPPlayer::DestroyPlayer()
{
	if (IsValid(this))
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			PlayerController->DisableInput(PlayerController);
			Destroy();
		}
	}
}

//void AFPPlayer::SpawnSpline_Implementation()
//{
//}
