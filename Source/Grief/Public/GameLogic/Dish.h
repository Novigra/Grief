// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dish.generated.h"

UCLASS()
class GRIEF_API ADish : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADish();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DishProperties")
	class USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DishProperties")
	class UStaticMeshComponent* Dish;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DishProperties")
	class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DishProperties")
	bool bCanInteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DishProperties")
	int32 MaxOfCookedDishes;

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
	void PlaceDish();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};