// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Socket.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SOCKETER_API USocket : public UObject
{
	GENERATED_BODY()
public:
	bool SetSocket(FSocket* Socket);
	FSocket* GetSocket();
	
private:
	FSocket* _Socket;
	
};
