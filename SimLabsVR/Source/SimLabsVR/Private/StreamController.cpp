// Fill out your copyright notice in the Description page of Project Settings.

#include "StreamController.h"
//#include "Android/AndroidMediaTextureUpdater.h"

// Sets default values
AStreamController::AStreamController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AStreamController::Init(UMediaTexture* NewMediaTexture, int width, int height) {
	MediaTexture = NewMediaTexture;
	textureWidth = width;
	textureHeight = height;
	TextureUpdater = SimlabsStream::CreateMediaTextureUpdater(MediaTexture, textureWidth, textureHeight);
	StreamCommander = SimlabsStream::CreateStreamCommander(TextureUpdater);
}

void AStreamController::Connect(FString Host, FString Port) {
	UE_LOG(LogTemp, Warning, TEXT("StreamController: call connect"));
	if (StreamCommander)
		StreamCommander->Connect(Host.Append(TEXT(":")).Append(Port));
}

void AStreamController::Disconnect() {
	UE_LOG(LogTemp, Warning, TEXT("StreamController: call disconnect"));
	if (StreamCommander)
		StreamCommander->Disconnect();
}

void AStreamController::BeginPlay()
{
	Super::BeginPlay();
	if (MediaTexture) {
		TextureUpdater = SimlabsStream::CreateMediaTextureUpdater(MediaTexture, textureWidth, textureHeight);
		StreamCommander = SimlabsStream::CreateStreamCommander(TextureUpdater);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("StreamController: media texture is null when begin play"))
	}
}

void AStreamController::BeginDestroy()
{
	Super::BeginDestroy();
	if (TextureUpdater)
		delete TextureUpdater;
	if (StreamCommander)
		delete StreamCommander;
}

// Called every frame
void AStreamController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (TextureUpdater)
		TextureUpdater->UpdateTexture();
}

