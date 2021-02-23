// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectoryCreatorComponent.h"
#include "HAL/FileManagerGeneric.h"

// Sets default values for this component's properties
UDirectoryCreatorComponent::UDirectoryCreatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UDirectoryCreatorComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UDirectoryCreatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDirectoryCreatorComponent::CreateDir() {
	
}