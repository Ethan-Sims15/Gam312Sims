// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "BuildingPart.generated.h"

UCLASS()
class GAM312_SIMS_API ABuildingPart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingPart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	//Creates unified pivot point for building
	UPROPERTY(EditAnywhere)
		UArrowComponent* PivotArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		float GridSize = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		FVector SnapOffset = FVector::ZeroVector; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		float ZOffset = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Building")
		FVector SnapLocationToGrid(const FVector& InLocation) const;
};
