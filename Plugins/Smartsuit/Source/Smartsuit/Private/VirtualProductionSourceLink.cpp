// Fill out your copyright notice in the Description page of Project Settings.

#include "VirtualProductionSourceLink.h"

VirtualProductionSourceLink::VirtualProductionSourceLink()
{
}

VirtualProductionSourceLink::~VirtualProductionSourceLink()
{
	Stop();
	
	if (Thread != NULL)
	{
		Thread->Kill(true);
		delete Thread;
	}
}


void VirtualProductionSourceLink::Start() {
	Stopping = false;
	FString ThreadName(FString::Printf(TEXT("VPStreamingNetwork%ld"), (long)(FDateTime::UtcNow().ToUnixTimestamp())));
	Thread = FRunnableThread::Create(this, *ThreadName, 8 * 1024, TPri_Normal);
	UE_LOG(LogTemp, Warning, TEXT(" - - - link started indeed!"));
}

uint32 VirtualProductionSourceLink::Run()
{
	bool added = false;
	while (!Stopping)
	{
		//if (Source) {
			UE_LOG(LogTemp, Display, TEXT("VirtualProductionSourceLink::Run - has source"));
		//}
		//else {
			//UE_LOG(LogTemp, Display, TEXT("VirtualProductionSourceLink::Run - no source"));
		//}

		FPlatformProcess::ConditionalSleep([this]() -> bool {
			return true;
		}, 0.01);
	}
	return 0;
}
