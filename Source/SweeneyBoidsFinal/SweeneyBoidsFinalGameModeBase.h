// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "C_Manager.h"
#include "SweeneyBoidsFinalGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SWEENEYBOIDSFINAL_API ASweeneyBoidsFinalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		ASweeneyBoidsFinalGameModeBase();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* AgentMesh;

	UPROPERTY() UC_Manager* Manager;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};