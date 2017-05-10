#pragma once

#include <WinSock2.h>

const char local_ip[] = "10.1.32.146";

/*A function to initiate the WinSock2 DLL.
The function returns true on
success and false on failure.*/
bool wsa_init(WSADATA& data);



/*A function to build a sockaddr object.
WARNING: this method can be used to create only
one object at a time. If function is used after an
object is created, the previous item will be modified.*/
void init_addr(sockaddr_in* addr, const char* ip, const unsigned int port);