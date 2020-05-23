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

#include "Socket.h"
#include "Socketer.h"

bool USocketerSocket::SetSocket(FSocket* Socket)
{
	_Socket = Socket;
	return false;
}

FSocket* USocketerSocket::GetSocket()
{
	return _Socket;
}
