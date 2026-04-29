

#include "RotatingItem.h"
#include "Components/StaticMeshComponent.h"


ARotatingItem::ARotatingItem()
{

	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	RotationSpeed = FRotator(0.f, 100.f, 0.f);
}


void ARotatingItem::BeginPlay()
{
	Super::BeginPlay();

}


void ARotatingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(RotationSpeed * DeltaTime);
}

