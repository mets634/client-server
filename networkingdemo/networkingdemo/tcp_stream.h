#pragma once

#include "network.h"

class tcp_stream
{
public:
	tcp_stream();
	tcp_stream(SOCKET* s);
	~tcp_stream();

	int read(char* buffer, int buf_size);
	int write(char* buffer, int buf_size);

	int get_status() const { return status; }

protected:
	SOCKET* m_socket;
	sockaddr* addr;
	int status;
};

