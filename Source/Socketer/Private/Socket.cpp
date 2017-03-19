// Fill out your copyright notice in the Description page of Project Settings.

#include "Socketer.h"
#include "Socket.h"

bool USocket::SetSocket(FSocket* Socket)
{
	_Socket = Socket;
	return false;
}

FSocket* USocket::GetSocket()
{
	return _Socket;
}
