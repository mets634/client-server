#include "debug.h"
#include <iostream>

using namespace std;

void debug(const char* msg)
{
	if (DEBUG)
		cout << "[DEBUG] " << msg << endl;
}

void error(const char* msg)
{
	cerr << "[ERROR] " << msg << endl;
}