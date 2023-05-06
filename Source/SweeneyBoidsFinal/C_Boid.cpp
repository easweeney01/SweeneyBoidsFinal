#include "C_Boid.h"

// Sets default values
AC_Boid::AC_Boid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AgentMesh"));
	RootComponent = Mesh;
	moveV = FVector(10.f);

}

// Called when the game starts or when spawned
void AC_Boid::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AC_Boid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DTime = DeltaTime;

	FVector pos = GetActorLocation();
	SetActorLocation(pos + moveV);
}

void AC_Boid::Initialize(UStaticMeshComponent* mesh, int id) {
	Mesh->SetStaticMesh(mesh->GetStaticMesh());
	ID = id;

	//Hope this reads well.
	UE_LOG(LogTemp, Warning, TEXT("Agent initialized."));
}


