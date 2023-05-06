// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Manager.h"


#define BOID_COUNT 20

void UC_Manager::Initialize(UWorld* world, UStaticMeshComponent* mesh) {

	UE_LOG(LogTemp, Warning, TEXT("Manager initialized"));

	w = world;
	if (w == nullptr) {
		return;
	}

	float num = (PI * 2.f) / BOID_COUNT;
	for (int i = 0; i < BOID_COUNT; i++) {
		FRotator rot = FRotator();

		FVector pos = FVector();
		pos.X = FMath::Sin(num * i) * 650.f;
		pos.Z = FMath::Cos(num * i) * 650.f;

		AC_Boid* boid = w->SpawnActor<AC_Boid>(pos, rot);
		boid->Initialize(mesh, i);
		Boids.Add(boid);
	}

	init = true;
}

void UC_Manager::doFlock() {
	for (int i = 0; i < Boids.Num(); i++) {
		AC_Boid* thisBoid = Boids[i];

		thisBoid->moveV += (RuleOne(i) * thisBoid->DTime) + (RuleTwo(i) * thisBoid->DTime)
			+ (RuleThree(i) * thisBoid->DTime) + (AimToLoc(i) * thisBoid->DTime);

		//thisBoid->GetActorLocation() = thisBoid->GetActorLocation() + thisBoid->moveV;
		thisBoid->SetActorLocation(thisBoid->GetActorLocation() + thisBoid->moveV);
	}
}

//Boids try to fly towards the centre of mass of neighbouring boids.
FVector UC_Manager::RuleOne(int id)
{
	FVector pc;
	for (int i = 0; i < Boids.Num(); i++) {
		if (Boids[i]->ID != id) {
			pc = pc + Boids[i]->GetActorLocation();
		}
	}

	pc = pc / (Boids.Num() - 1);
	return(pc - Boids[id]->GetActorLocation()) / 100;
}

//Boids try to keep a small distance away from other objects (including other boids).
FVector UC_Manager::RuleTwo(int id)
{
	FVector c = FVector(0, 0, 0);

	for (int i = 0; i < Boids.Num(); i++) {
		if (Boids[i]->ID != id) {
			if (FVector::Dist(Boids[i]->GetActorLocation(), Boids[id]->GetActorLocation()) < 100.0)
				c = c - (Boids[i]->GetActorLocation() - Boids[id]->GetActorLocation());
		}
	}

	return c;
}

//Boids try to match velocity with near boids.
FVector UC_Manager::RuleThree(int id)
{
	FVector matchV = FVector(0, 0, 0);

	for (int i = 0; i < Boids.Num(); i++) {
		if (Boids[i]->ID != id) {
			matchV = matchV + Boids[i]->moveV;
		}
	}
	matchV /= (Boids.Num() - 1);

	return(matchV - Boids[id]->moveV) / 8;
}

//Aims for a Location
FVector UC_Manager::AimToLoc(int id)
{
	FVector Place = FVector(20, 20, 20);
	return (Place - Boids[id]->GetActorLocation()) / 100;
}

