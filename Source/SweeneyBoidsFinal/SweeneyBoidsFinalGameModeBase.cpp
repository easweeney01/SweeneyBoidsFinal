// Copyright Epic Games, Inc. All Rights Reserved.


#include "SweeneyBoidsFinalGameModeBase.h"

ASweeneyBoidsFinalGameModeBase::ASweeneyBoidsFinalGameModeBase() {
    AgentMesh = CreateDefaultSubobject<UStaticMeshComponent>("AgentMesh");
    PrimaryActorTick.bCanEverTick = true;

    //    return 0;
}

void ASweeneyBoidsFinalGameModeBase::BeginPlay() {
    Super::BeginPlay();

    Manager = NewObject<UC_Manager>();
    Manager->Initialize(GetWorld(), AgentMesh);

    UE_LOG(LogTemp, Warning, TEXT("GAMEMODE BEGINPLAY()"));
}

void ASweeneyBoidsFinalGameModeBase::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    Manager->doFlock();
};