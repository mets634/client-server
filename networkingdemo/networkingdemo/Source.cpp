#include <iostream>
#include "tcp_server.h"
#include "tcp_client.h"
#include <string>
#include "debug.h"
#include <thread>

using namespace std;



void echo_read(tcp_stream& stream)
{
	char buffer[1024];
	while (strcmp(buffer, "exit"))
	{
		int length = stream.read(buffer, sizeof(buffer));
		if (length > 0)
			cout << "[*] RECEIVED (" << length << " BYTES): " << buffer << endl;
	}
}

void echo_write(tcp_stream& stream)
{
	char buffer[1024];
	while (strcmp(buffer, "exit"))
	{
		cin >> buffer;
		int temp = stream.write(buffer, sizeof(buffer));

		char msg[1024];
		sprintf(msg, "Sent %s (%i bytes)", buffer, temp);
		debug(msg);
	}
}

void echo(tcp_stream& stream)
{
	thread read(echo_read, stream);
	thread write(echo_write, stream);

	read.join();
	write.join();
}

void echo_server(unsigned int port)
{
	char msg[1024];
	sprintf(msg, "Starting server on port %i...", port);
	debug(msg);

	tcp_server server;
	tcp_stream stream (server.listen(port));
	echo(stream);
}

void echo_client(unsigned int port)
{
	char msg[1024];
	sprintf(msg, "Starting client on port %i...", port);
	debug(msg);

	tcp_client client;
	client.connect(local_ip, port);

	debug("Connection established");
	echo(client);
}

int main()
{
	debug("Initializing Winsock2...");

	// initialize winsock2
	WSADATA data;  // DO NOT TOUCH THIS OTHER THAN INITIALIZATION
	wsa_init(data);

	///// END OF INITIALIATION /////

	debug("Waiting for user input...");

	const int port = 55555;
	const char ip[] = "10.1.32.146";

	string input = "";
	cin >> input;

	if (input == "server")
		echo_server(port);
	else
		echo_client(port);

	debug("Cleaning up Winsock2...");

	///// START OF CLEANUP /////
	WSACleanup();
	return 0;
}