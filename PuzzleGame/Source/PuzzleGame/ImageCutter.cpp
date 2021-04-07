// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageCutter.h"
#include "opencv2\highgui\highgui.hpp"

using namespace cv;

// Sets default values for this component's properties
UImageCutter::UImageCutter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UImageCutter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UImageCutter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UImageCutter::cutTheImage(FString fullName, uint8 size, bool offline) {
	Mat img;
	FString pathRead = FPaths::ProjectDir();
	
	if (offline) {
		pathRead += FString("Offline/");
	}
	else {
		pathRead += FString("Online/");
	}

	const std::string imageNamePath = std::string(TCHAR_TO_UTF8(*pathRead)) + std::string(TCHAR_TO_UTF8(*fullName));
	img = imread(imageNamePath, 1);
	if (!img.data || img.empty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't open image"));
	}
	else {
		FString path = FPaths::ProjectDir();

		if (offline) {
			path += FString("OfflineCut/");
		}
		else {
			path += FString("OnlineCut/");
		}
		
		// get the image data
		int height = img.rows;
		int width = img.cols;
		int cntr = 0;

		// ciklussal sokfele darabban
		//subdivide(cntr, image, 3, 3);
		int colDivisor = size;
		int rowDivisor = size;

		for (int y = 0; y < img.cols; y += img.cols / colDivisor)
		{
			for (int x = 0; x < img.rows; x += img.rows / rowDivisor)
			{
				if (0 <= x && 0 <= (img.cols / colDivisor) && y + (img.cols / colDivisor) <= img.cols && 0 <= y && 0 <= (img.rows / rowDivisor) && x + (img.rows / rowDivisor) <= img.rows)
				{
					Mat cutted = img(cv::Rect(y, x, (img.cols / colDivisor), (img.rows / rowDivisor)));

					// saving part:
					std::string savingName = std::string(TCHAR_TO_UTF8(*path)) + std::to_string(++cntr) + std::string(TCHAR_TO_UTF8(*fullName));
					imwrite(savingName, cutted);
				}
			}
		}
	}
}