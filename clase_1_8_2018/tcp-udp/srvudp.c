#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int num[2];
	int s, res, clilen;
	struct sockaddr_in server_addr, client_addr;

	s =  socket(AF_INET, SOCK_DGRAM, 0);  

	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = 7200;

	bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
        clilen = sizeof(client_addr);

	while (1)
	{
		recvfrom(s, (char *) num, 2* sizeof(int), 0, 
			(struct sockaddr *)&client_addr, &clilen);

		res = num[0] + num[1];

		sendto(s, (char *)&res, sizeof(int), 0,
			(struct sockaddr *)&client_addr,  clilen);
	}

}
