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
	int sd;
	struct sockaddr_in server_addr;
	struct hostent *hp;
   int num[2], res;

	sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	bzero((char *)&server_addr, sizeof(server_addr));
	hp = gethostbyname ("127.0.0.1");
        
        memcpy (&(server_addr.sin_addr), hp->h_addr, hp->h_length);
        /*( direccion dominio del servidior, direccion IP, largo de la direcion IP)*/
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = 4200;
	

// se establece la conexi�n
	connect(sd, (struct sockaddr *)&server_addr,sizeof(server_addr));

	num[0]=5;
	num[1]=2;

	write(sd, (char *) num, 2 *sizeof(int));	// env�a la petici�n
	
	read(sd, &res, sizeof(int));	// recibe la respuesta
	
	printf("Resultado es %d \n", res);
   close (sd);
	exit(0);
}
