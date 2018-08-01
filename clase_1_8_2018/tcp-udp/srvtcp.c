#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>



void main(int argc, char *argv[])
{
	struct sockaddr_in server_addr,  client_addr;
	int sd, sc;
	int size, val;
	int num[2],  res;

	sd =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        val = 1;
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *) &val, sizeof(int));
	
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;	
        server_addr.sin_port = 4200;

	bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        listen(sd, 5);
	size = sizeof(client_addr);
	while (1)
	{
		printf("esperando conexion\n");
                /*establece conexion entrante a partir del cliente*/
		sc = accept(sd, (struct sockaddr *)&client_addr,&size);
        			
		read(sc, (char *) num, 2 *sizeof(int));   // recibe la petició

		res = num[0] + num[1];

		write(sc, &res, sizeof(int));	// se envía el resultado	
		
		close(sc);
        }

	close (sd);
	exit(0);
}	
