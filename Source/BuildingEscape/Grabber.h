// Copyright Rafal Sikora

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <PhysicsEngine/PhysicsHandleComponent.h>
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	float PlayerReach = 100.f;
	UPROPERTY()
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPROPERTY()
	UInputComponent* InputComponent = nullptr;

	void Grab();
	void Released();
	void FindPhysicsHandle();
	void SetupInputComponent();

	//Return first actor within reach with the physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	//Return the line trace end
	FVector GetPlayerReach() const;

	//Get player position in the world
	FVector GetPlayerWorldPosition() const;
	
};
