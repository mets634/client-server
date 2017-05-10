#pragma once

#include "network.h"
#include "tcp_stream.h"

class tcp_client : public tcp_stream
{
public:
	tcp_client();
	~tcp_client();

	void connect(const char* ip, const int port);

	bool is_connected() const { return connected; }
private:
	bool connected;
};

