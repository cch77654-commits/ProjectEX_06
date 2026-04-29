
#include "MovingItem.h"
#include "Components/StaticMeshComponent.h"


AMovingItem::AMovingItem()
{

	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	MoveDirection = FVector(1, 0, 0);
	MoveSpeed = 200.f;
	MaxRange = 300.f;

	CurrentDistance = 0.f;
	Direction = 1;
}


void AMovingItem::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MoveDirection = MoveDirection.GetSafeNormal();
}

void AMovingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float MoveStep = MoveSpeed * DeltaTime;

	CurrentDistance += MoveStep;


	if (CurrentDistance >= MaxRange)
	{
		CurrentDistance = 0.f;
		Direction *= -1;
	}

	FVector Offset = MoveDirection * MoveStep * Direction;
	AddActorWorldOffset(Offset);
}

