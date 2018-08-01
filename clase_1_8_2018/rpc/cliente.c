#include "suma.h"

void main( int argc, char* argv[] )
{
	CLIENT *clnt;
	int  *res;
   peticion  suma_1_arg;
	char *host;

	if(argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];

/* localiza al servidor */
   clnt = clnt_create(host, SUMAR, SUMAVER, "udp");
   if (clnt == NULL) {
       clnt_pcreateerror(host);
       exit(1);
   }
	suma_1_arg.a = 5;
	suma_1_arg.b = 2;

   res = suma_1(&suma_1_arg, clnt);
   if (res == NULL) {
       clnt_perror(clnt, "call failed:");
   }
	printf("La suma es %d\n", *res);
   clnt_destroy( clnt );

}

