// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Boid.generated.h"

UCLASS()
class SWEENEYBOIDSFINAL_API AC_Boid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AC_Boid();

	void Initialize(UStaticMeshComponent* mesh, int id);
	UStaticMeshComponent* Mesh;

	//Movement Vector
	FVector moveV;

	//Variables
	float DTime;
	int ID;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};