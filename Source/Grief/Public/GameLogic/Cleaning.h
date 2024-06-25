// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cleaning.generated.h"

UCLASS()
class GRIEF_API ACleaning : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACleaning();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CleanProperties")
	class USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CleanProperties")
	class UStaticMeshComponent* Broom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CleanProperties")
	class UBoxComponent* BoxCollision;

	UPROPERTY()
	class AMotherRabbit* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void CollectBroom();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
