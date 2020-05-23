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

#include "SocketerBPLibrary.h"
#include "Socketer.h"

USocketerBPLibrary::USocketerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

USocketerSocket* USocketerBPLibrary::Connect(FString Host, int32 port, bool& bSuccessful)
{
	// Create an FSocket pointer to work with and an USocke pointer to return.
	FSocket* MySockTemp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("Socketer TCP Socket"), false);
	USocketerSocket* NetSock = NewObject<USocketerSocket>();

	// Now attempt to parse (& resolve) up the passed in hostname or IP.
	FAddressInfoResult LookupResult = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetAddressInfo(*Host, nullptr, EAddressInfoFlags::Default, NAME_None);
	if (LookupResult.ReturnCode != ESocketErrors::SE_NO_ERROR || LookupResult.Results.Num() < 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to resolve host \"%s\"!"), *Host);
		bSuccessful = false;
		return nullptr;
	}

	// Lookup was a success! Grab the first result and use the passed in port
	TSharedRef<FInternetAddr> SockAddr = LookupResult.Results[0].Address;
	SockAddr->SetPort(port);

	// Attempt to connect, and store if it succeeded in a variable
	bool connected = MySockTemp->Connect(*SockAddr);

	// Verify it is connected
	if (!connected)
	{
		// And if not log an error and return an error
		UE_LOG(LogTemp, Error, TEXT("Could not connect"));
		bSuccessful = false;
		return nullptr;
	}

	// Set the UObject wrappers its socket to the connected one
	NetSock->SetSocket(MySockTemp);

	bSuccessful = true;
	return NetSock;
}

bool USocketerBPLibrary::SendMessage(USocketerSocket * Connection, FString Message)
{
	
	// If the passed in socket is not valid
	if (!IsValid(Connection))
	{
		return false;
	}

	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		return false;
	}

	// Serialize the message
	TCHAR *serializedChar = Message.GetCharArray().GetData();
	// Get / setup parameters
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;

	// Send the message
	bool successful = MySocket->Send((uint8*)TCHAR_TO_UTF8(serializedChar), size, sent);

	// And check if there was an error
	if (!successful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error sending message!!"));
		return false;
	}
	else
	{
		return true;
	}
}

bool USocketerBPLibrary::GetMessage(USocketerSocket* Connection, FString &Message)
{
	// If the passed in socket is not valid
	if (!IsValid(Connection))
	{
		return false;
	}

	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		return false;
	}


	// Credit to RAMA for this converter!
	//Binary Array!
	TArray<uint8> BinaryData;
	uint32 Size;

	while (MySocket->HasPendingData(Size))
	{
		// Be sure that the array doesn't become absolutely insanely large
		BinaryData.Init(0, FMath::Min(Size, 65507u));

		// Set the counter for the ammount of bytes read to 0
		int32 Read = 0;
		// Recieve the data from the socket and put it into the binary array
		MySocket->Recv(BinaryData.GetData(), BinaryData.Num(), Read);
	}

	// Check if there was actually data read into the array
	if (BinaryData.Num() <= 0)
	{
		// No data was read!
		UE_LOG(LogTemp, Warning, TEXT("No data to read!"));
		return false;
	}
	else
	{
		// Be sure to \0 terminate the array
		BinaryData.Add(0);
		// Convert it to an fstring and set the passed in message parameter
		Message = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryData.GetData())));
		return true;
	}


}

bool USocketerBPLibrary::HasPendingData(USocketerSocket * Connection)
{
	// If the passed in socket is not valid
	if (!IsValid(Connection))
	{
		return false;
	}

	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		return false;
	}

	// Unused but required for the function to work
	uint32 Size;

	// Return if the socket has pending data
	return MySocket->HasPendingData(Size);
}

bool USocketerBPLibrary::CloseConnection(USocketerSocket * Connection)
{
	// If the passed in socket is not valid
	if (!IsValid(Connection))
	{
		return false;
	}

	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		return false;
	}

	// Attempt to close it and return if it was successful or not
	return MySocket->Close();
}

