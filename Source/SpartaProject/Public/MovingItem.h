

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingItem.generated.h"

UCLASS()
class SPARTAPROJECT_API AMovingItem : public AActor
{
	GENERATED_BODY()

public:

	AMovingItem();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
	// 메시
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// 시작 위치
	FVector StartLocation;

	// 이동 방향 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Movement")
	FVector MoveDirection;

	// 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Movement")
	float MoveSpeed;

	// 이동 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Movement")
	float MaxRange;

private:
	float CurrentDistance;
	int32 Direction; // 1 or -1
};