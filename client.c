#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8000
#define ADDR "127.0.0.1"
//#define ADDR "10.50.17.118"

int main(){
	int serverId, clientId;
	char buffer[1024];
	struct sockaddr_in serverAddress;
	socklen_t addr_size;

	printf("Connecting...\n");

	// Create client socket
	clientId = socket(AF_INET, SOCK_STREAM, 0);

	// Set server address
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = inet_addr(ADDR);
	memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);

	// Connect client to server
	addr_size = sizeof serverAddress;
	if(connect(clientId, (struct sockaddr *) &serverAddress, addr_size)!=0){
		printf("Error connecting to server!\n");
		return 0;
	}

	printf("Connected to server...\n");

	// post to server
	strcpy(buffer, "POST /?number=hello HTTP/1.1\r\nHost: 127.0.0.1:8000\r\n\r\n");
	send(clientId, buffer, 54, 0);
	// write(clientId, buffer, 96);

	// Read message from server
	recv(clientId, buffer, 1024, 0);
	printf("Server: %s\n", buffer);

	return 0;
}

