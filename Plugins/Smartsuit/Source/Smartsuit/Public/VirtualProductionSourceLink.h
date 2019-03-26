// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Core/Public/Containers/UnrealString.h"
#include "Engine.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Runtime/Core/Public/HAL/RunnableThread.h"
//#include "VirtualProductionSource.h"
//#include "Runtime/Core/Public/Lumin/LuminPlatformProcess.h"

class SMARTSUIT_API VirtualProductionSourceLink : public FRunnable
{
public:
	VirtualProductionSourceLink();
	~VirtualProductionSourceLink();

	/// @private
	virtual uint32 Run() override;

	//void RegisterSource(FVirtualProductionSource *in_source) {
	//	Source = in_source;
	//}

	/**
	* Checks whether the listener is listening for incoming connections.
	*
	* @return true if it is listening, false otherwise.
	*/
	bool IsActive() const
	{
		return (!Stopping);
	}


	virtual void Stop() override
	{
		Stopping = true;
	}


	void Start();

	/// @private
	virtual void Exit() override { }
private:
	bool Stopping;
	FRunnableThread* Thread = NULL;
	//FVirtualProductionSource *Source = NULL;
};
