// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemyActor.h"
#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnEnemyActor::ASpawnEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	random = 1;
}

// Called when the game starts or when spawned
void ASpawnEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AClickMoveCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Begin"));
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ASpawnEnemyActor::KeepSpawn, 5.f, true);
	
}

// Called every frame
void ASpawnEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnEnemyActor::KeepSpawn()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("KeepSpawn"));
	FTransform Transform;
	Transform.SetLocation(player->GetActorLocation() + (player->GetActorForwardVector() * 300.f * -1));
	GetWorld()->SpawnActor<AEnemyCharacter>(AEnemyCharacter::StaticClass(), Transform);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%d"), FMath::RandRange(-2, 2)));

	/*random = FMath::RandRange(-2, 2);
	if (random != 0)
	{
		Transform.SetLocation(player->GetActorLocation() + (player->GetActorForwardVector() * 300.f * random));
		GetWorld()->SpawnActor<AEnemyCharacter>(AEnemyCharacter::StaticClass(), Transform);
	}*/
}

