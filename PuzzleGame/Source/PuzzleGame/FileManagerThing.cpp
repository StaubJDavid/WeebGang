// Fill out your copyright notice in the Description page of Project Settings.

#include "FileManagerThing.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"

// Sets default values
AFileManagerThing::AFileManagerThing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFileManagerThing::BeginPlay()
{
	Super::BeginPlay();
	
	FFileManagerGeneric fmg;
	FString path = FPaths::ProjectDir();

	path += FString("Images");
	FString pathFull = FPaths::ConvertRelativePathToFull(path);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *pathFull);

	if (fmg.MakeDirectory(*pathFull, true)) {
		UE_LOG(LogTemp, Warning, TEXT("Made a directory at:"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *pathFull);
	}

	//Starts the external process(removed)
	/*FPlatformProcess::CreateProc(TEXT("G:/School/Szoftfejl/PuzzleGame/Source/ConsoleApp1.exe"), nullptr, true, false, false, nullptr, 0, TEXT("G:/School/Szoftfejl/PuzzleGame/Source"), nullptr);
	UE_LOG(LogTemp, Warning, TEXT("Did the create process?"));*/
}

// Called every frame
void AFileManagerThing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

