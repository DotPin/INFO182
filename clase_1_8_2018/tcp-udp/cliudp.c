#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>


void main(int argc, char *argv[]){
	struct sockaddr_in server_addr, client_addr;
	struct hostent *hp;
	int s, num[2], res;

	if (argc != 2){
		printf("Uso: client <direccion_servidor> \n");
		exit(0);
	}

	s =  socket(AF_INET, SOCK_DGRAM, 0);
   hp = gethostbyname (argv[1]);
        
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	memcpy (&(server_addr.sin_addr), hp->h_addr, hp->h_length);
	server_addr.sin_port = 7200;


bzero((char *)&client_addr, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr  = INADDR_ANY;
	client_addr.sin_port  = htons(0);

	bind (s, (struct sockaddr *)&client_addr, sizeof(client_addr));
	
	num[0] = 2;	   num[1] = 5;

	sendto(s, (char *)num, 2 * sizeof(int), 0, 
		(struct sockaddr *) &server_addr, sizeof(server_addr));
				
	recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
	
	printf("2 + 5 = %d\n", res);	
	close(s);
}
