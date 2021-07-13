// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()



private:
	UPROPERTY(EditAnywhere)
	float FireRate = 2;
	
	UPROPERTY(EditAnywhere)
	float FireRange = 500;


	FTimerHandle FireRateTimerHandle;
	APawnTank *PlayerPawn;


	void CheckFireCondition();
	float ReturnDistancToPlayer();

public:
	 
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;

	
};
