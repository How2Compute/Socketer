// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Socket.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "SocketerBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class USocketerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "Socketer sample test testing"), Category = "SocketerTesting")
	static float SocketerSampleFunction(float Param);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect to a TCP server", Keywords = "Socketer connect tcp tcpconnect socketerconnect"), Category = "Networking|Socketer")
	static USocket* Connect(FString IP, int32 port, bool &success);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send message to the server", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool SendMessage(USocket* Connection, FString Message);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get buffer (converted to FText) from server", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool GetMessage(USocket* Connection, FString &Message);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "HasPendingData", Keywords = "Socketer send message tcpsend tcp tcpdisconnect socketersend"), Category = "Networking|Socketer")
	static bool HasPendingData(USocket* Connection);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close connection to TCP server", Keywords = "Socketer disconnect close tcpclose tcp tcpdisconnect socketerdisconnect"), Category = "Networking|Socketer")
	static bool CloseConnection(USocket* Connection);

};
