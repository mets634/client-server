#include "tcp_server.h"
#include "tcp_stream.h"
#include "debug.h"
#include <iostream>

char buffer[1024];

tcp_server::tcp_server() : status(0)
{
	m_socket = new SOCKET; 
	addr = new sockaddr;
	*m_socket = socket(AF_INET, SOCK_STREAM, 0);  // initialize socket to TCP stream
}


tcp_server::~tcp_server()
{
	closesocket(*m_socket);
	if (m_socket != NULL)
		delete m_socket;
	if (addr != NULL)
		delete addr;
}

tcp_stream tcp_server::listen(unsigned int port)
{
	const int MAX_CONNECTIONS = 1;

	init_addr((sockaddr_in*)addr, local_ip, port);  // create addr

	// bind socket to port
	status = bind(*m_socket, addr, sizeof(*addr)); 
	if (status == SOCKET_ERROR)  // error, do not continue
	{
		sprintf(buffer, "Failed to bind socket with code: %i", WSAGetLastError());
		error(buffer);
		return NULL;
	}
		

	// listen for connections
	status = ::listen(*m_socket, MAX_CONNECTIONS);
	if (status == SOCKET_ERROR)  // error, do not continue
	{
		sprintf(buffer, "Failed to listen to port with code: %i", WSAGetLastError());
		error(buffer);
		return NULL;
	}

	// accept incoming connection
	SOCKET* incoming = new SOCKET;
	*incoming = accept(*m_socket, NULL, NULL);

	debug("Connection established");

	return tcp_stream(incoming);
}
