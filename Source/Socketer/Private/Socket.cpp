/* Copyright 2017-2019 HowToCompute. All Rights Reserved.
* You may use, distribute and modify this code under the
* terms of the MIT license.
*
* You should have received a copy of the MIT license with
* this file. If not, please visit: https://github.com/How2Compute/Socketer
*/

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
