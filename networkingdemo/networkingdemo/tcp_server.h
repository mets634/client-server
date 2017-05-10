#pragma once

#include "network.h"

class tcp_stream;

class tcp_server
{
public:
	tcp_server();
	~tcp_server();

	tcp_stream listen(unsigned int port);

	int get_status() const { return status; }

private:
	SOCKET* m_socket;
	sockaddr* addr;
	int status;
};

