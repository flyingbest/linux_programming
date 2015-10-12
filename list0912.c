#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXCONNECTION	5
#define BUFSIZE				256

static void session_with_client (int);

int main(int argc, char *argv[]){
	int ssid, csid;
	struct sockaddr_in s_addr, c_addr;

	
