

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingItem.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotatingItem : public AActor
{
	GENERATED_BODY()

public:

	ARotatingItem();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	// 메시
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingItem|Rotation")
	FRotator RotationSpeed;

};
