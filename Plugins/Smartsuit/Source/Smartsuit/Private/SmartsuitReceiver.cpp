// Copyright 2019 Rokoko Electronics. All Rights Reserved.

#include "SmartsuitReceiver.h"
#include "Smartsuit.h"



// Sets default values
ASmartsuitReceiver::ASmartsuitReceiver()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASmartsuitReceiver::BeginPlay()
{
	Super::BeginPlay();
	StartListener();
	enabled = true;
	realLife = true;
}

void ASmartsuitReceiver::BeginDestroy() 
{
	Super::BeginDestroy();
	StopListener();
}

// Called every frame
void ASmartsuitReceiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ASmartsuitReceiver::StartListener() 
{
	UE_LOG(LogTemp, Warning, TEXT("Listening..."));
	//listener.Start(streamingDataPort);
	VPlistener.Start(VPListenPort);
}

void ASmartsuitReceiver::StopListener() 
{
	//listener.Stop();
	VPlistener.Stop();
	UE_LOG(LogTemp, Warning, TEXT("Not listening..."));
}

FSuitData * ASmartsuitReceiver::GetSmartsuit(FString suitName)
{
	return VPlistener.GetSmartsuitByName(suitName);
}

FProp* ASmartsuitReceiver::GetPropByNameFromVP(FString name, bool isLive) 
{
	return VPlistener.GetPropByName(name, isLive);
}

FTracker* ASmartsuitReceiver::GetTrackerByNameFromVP(FString name, bool isLive) 
{
	return VPlistener.GetTrackerByName(name, isLive);
}

TArray<FString> ASmartsuitReceiver::GetAvailableSmartsuits() 
{
	return VPlistener.GetAvailableSmartsuits();
}

void ASmartsuitReceiver::SetSupportsWiFiAPI(FString suitname) 
{
	//listener.wifiSupportedSuits.Add(suitname);
}