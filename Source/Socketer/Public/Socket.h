/* Copyright 2017-2019 HowToCompute. All Rights Reserved.
* You may use, distribute and modify this code under the
* terms of the MIT license.
*
* You should have received a copy of the MIT license with
* this file. If not, please visit: https://github.com/How2Compute/Socketer
*/

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
