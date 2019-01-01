// Fill out your copyright notice in the Description page of Project Settings.

#include "Socket.h"
#include "Socketer.h"

bool USocket::SetSocket(FSocket* Socket)
{
	_Socket = Socket;
	return false;
}

FSocket* USocket::GetSocket()
{
	return _Socket;
}
