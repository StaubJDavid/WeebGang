// Fill out your copyright notice in the Description page of Project Settings.

#include "FileManagerThing.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"
#include "opencv2\highgui\highgui.hpp"


using namespace cv;

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

	UE_LOG(LogTemp, Warning, TEXT("Starting imgTest"));
	imgTest();
	//Starts the external process(removed)
	/*FPlatformProcess::CreateProc(TEXT("G:/School/Szoftfejl/PuzzleGame/Source/ConsoleApp1.exe"), nullptr, true, false, false, nullptr, 0, TEXT("G:/School/Szoftfejl/PuzzleGame/Source"), nullptr);
	UE_LOG(LogTemp, Warning, TEXT("Did the create process?"));*/
}

// Called every frame
void AFileManagerThing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFileManagerThing::imgTest() {
	Mat img;

	img = imread("G:/School/Szoftfejl/PuzzleGame/CutTest/gnocchi.jpg", 1);
	if (!img.data || img.empty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't open image"));
	}
	else {
		FString path = FPaths::ProjectDir();

		path += FString("CutTest/");
		// get the image data
		int height = img.rows;
		int width = img.cols;
		int cntr = 0;

		// ciklussal sokfele darabban
		//subdivide(cntr, image, 3, 3);
		int colDivisor = 3;
		int rowDivisor = 3;

		for (int y = 0; y < img.cols; y += img.cols / colDivisor)
		{
			for (int x = 0; x < img.rows; x += img.rows / rowDivisor)
			{
				if (0 <= x && 0 <= (img.cols / colDivisor) && y + (img.cols / colDivisor) <= img.cols && 0 <= y && 0 <= (img.rows / rowDivisor) && x + (img.rows / rowDivisor) <= img.rows)
				{
					Mat cutted = img(cv::Rect(y, x, (img.cols / colDivisor), (img.rows / rowDivisor)));

					// saving part:
					std::string savingName = std::string(TCHAR_TO_UTF8(*path)) + "image" + std::to_string(++cntr) + ".jpg";
					imwrite(savingName, cutted);
				}
			}
		}
	}
	
}