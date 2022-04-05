/* Copyright 2017-2020 HowToCompute. All Rights Reserved.
* You may use, distribute and modify this code under the
* terms of the MIT license.
*
* You should have received a copy of the MIT license with
* this file. If not, please visit: https://github.com/How2Compute/Socketer.
*
* This plugin provides a very simple, almost 1:1 mapping
* between Unreal Engine's FSocket library and Blueprints.
* For a more easy-to-use plugin, with support for SSL,
* encryption, "managed" sockets, timely updates, premium
* support and more please consider taking a look at our
* commercial offering, NetShield:
* https://www.unrealengine.com/marketplace/en-US/product/netshield
*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Socket.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "SocketerBPLibrary.generated.h"

/* 
* TCP FSocket wrapper library for Unreal Engine 4.
* 
* NOTE: This is a near 1-on-1wrapper, so use it with caution.
* You are fully responsible for closing sockets, and ensuring
* that there is data to be read. Not doing so, can result in
* undefined and unwanted behavior.
*/
UCLASS()
class USocketerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/*
	* Connect to a TCP server.
	* 
	* @param Host The host name or IP address of the server you'd like to connect to.
	* @param port The port your server application is listening on.
	* 
	* @param success True if a connection was correctly established, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect to a TCP server", Keywords = "Socketer connect tcp tcpconnect socketerconnect"), Category = "Networking|Socketer")
	static USocketerSocket* Connect(FString Host, int32 port, bool &success);

	/*
	* Send a string over a TCP connection.
	* 
	* @Param Connection TCP socket connection to send the message over.
	* @Param Message The string to send to the server.
	*
	* @return True if a message was successfully sent, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send message to the server", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool SendMessage(USocketerSocket* Connection, FString Message);
	
	/*
	* Receive a string from a TCP connection. WARNING: Game could hang till timeout if no data is available, please check using HasPendingData first.
	*
	* @Param Connection TCP socket connection to receive the message from.
	* 
	* @Param Message The received message
	* @return True if a message was successfully received, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get buffer (converted to FString) from server", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool GetMessage(USocketerSocket* Connection, FString &Message);

	/*
	* Checks if a TCP connection has any pending data.
	*
	* @Param Connection TCP socket connection to check.
	*
	* @Param Message The received message
	* @return True if a message was successfully received, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "HasPendingData", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool HasPendingData(USocketerSocket* Connection);

	/*
	* Closes a TCP connection
	*
	* @Param Connection The TCP connection to close
	* 
	* @return True if the socket was successfully closed, false otherwise.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close connection to TCP server", Keywords = "Socketer disconnect close tcpclose tcp tcpdisconnect socketerdisconnect"), Category = "Networking|Socketer")
	static bool CloseConnection(USocketerSocket* Connection);
};
