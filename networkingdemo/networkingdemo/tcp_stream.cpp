#include "tcp_stream.h"


tcp_stream::tcp_stream() : status(0)
{
	m_socket = new SOCKET;
	addr = new sockaddr;
	*m_socket = socket(AF_INET, SOCK_STREAM, 0);
}

tcp_stream::tcp_stream(SOCKET* s) : m_socket(s), status(0) {}


tcp_stream::~tcp_stream()
{
	closesocket(*m_socket);
	if (m_socket != NULL)
		delete m_socket;
	if (addr != NULL)
		delete addr;
}


int tcp_stream::read(char* buffer, int buf_length)
{
	return recv(*m_socket, buffer, buf_length, 0);
}

int tcp_stream::write(char* buffer, int buf_length)
{
	return send(*m_socket, buffer, buf_length, 0);
}