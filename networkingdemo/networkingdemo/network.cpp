#include "network.h"

void init_addr(sockaddr_in* service, const char* ip, const unsigned int port)
{
	service->sin_family = AF_INET;  // ipv4
	service->sin_addr.s_addr = inet_addr(ip);
	service->sin_port = htons(port);
}

bool wsa_init(WSADATA& data)
{
	const WORD wVersion = MAKEWORD(2, 2);
	const int err = WSAStartup(wVersion, &data);

	return err == NO_ERROR;
}