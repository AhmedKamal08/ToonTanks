// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent*  Camera;

	FVector MoveDirection;
	FQuat RotationDirection;
	
	
	APlayerController* PlayerControllerRef;

	bool bIsPlayerAlive = true;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();
	
	UPROPERTY(EditAnywhere)
	float Movespeed = 100;
	
	UPROPERTY(EditAnywhere)
	float RotateSpeed = 100;
public:
	APawnTank();

	bool GetIsPlayerAlive();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
