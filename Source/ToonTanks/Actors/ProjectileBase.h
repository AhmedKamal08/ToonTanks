// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"
class UProjectileMovementComponent;
UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Component"   )
	UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Component" )
	UStaticMeshComponent * ProjectileMesh;

	UPROPERTY(EditDefaultsOnly,    Category = "Damage")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(VisibleAnywhere  )
	float MovmentSpeed = 1330;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* HitParticle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleTrail;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* LaunchSound;


	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UMatineeCameraShake> HitShake;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	float Damge = 50;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* otherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
