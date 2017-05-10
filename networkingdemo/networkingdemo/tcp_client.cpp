#include "tcp_client.h"
#include <iostream>
#include "debug.h"

char buffer1[1024];

tcp_client::tcp_client() : tcp_stream(), connected(false) {} // initialize socket to TCP stream

tcp_client::~tcp_client() {}

void tcp_client::connect(const char* ip, const int port)
{
	init_addr((sockaddr_in*)addr, ip, port);
	status = ::connect(*m_socket, addr, sizeof(*addr));
	if (status == SOCKET_ERROR)  // error, do not continue
	{
		sprintf(buffer1, "Failed to connect to port with code: %i", WSAGetLastError());
		error(buffer1);
	}
}