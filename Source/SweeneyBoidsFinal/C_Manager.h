#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "C_Boid.h"
#include "C_Manager.generated.h"

/**
 *
 */
UCLASS()
class SWEENEYBOIDSFINAL_API UC_Manager : public UObject
{
public:
	GENERATED_BODY()
		void Initialize(UWorld* world, UStaticMeshComponent* mesh);
	void doFlock();

	FVector RuleOne(int id);
	FVector RuleTwo(int id);
	FVector RuleThree(int id);
	FVector AimToLoc(int id);

private:
	UWorld* w;
	bool init;
	TArray<class AC_Boid*> Boids;
};
