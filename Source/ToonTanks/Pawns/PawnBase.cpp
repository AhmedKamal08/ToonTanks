// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "ToonTanks/Actors/ProjectileBase.h"
#include "ToonTanks/Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpwnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spwn Point "));
	ProjectileSpwnPoint->SetupAttachment(TurretMesh);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

}

// Called when the game starts or when spawned

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	FVector LookAtClean = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();
	
	FRotator  TurretRotaion = FVector(LookAtClean-StartLocation).Rotation();

	TurretMesh->SetWorldRotation(TurretRotaion);
}

void APawnBase::Fire()
{

	if (ProjectileClass) {
		FVector SpawnLoc = ProjectileSpwnPoint->GetComponentLocation();
		FRotator SpawnRot = ProjectileSpwnPoint->GetComponentRotation();
		AProjectileBase * TempProjectile = GetWorld()->SpawnActor< AProjectileBase>(ProjectileClass, SpawnLoc, SpawnRot);
	
		TempProjectile->SetOwner(this);
	}
}

void APawnBase::HandleDestruction()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
	UGameplayStatics::SpawnSoundAtLocation(this, DeathSound, GetActorLocation());
	GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathShake);
}
