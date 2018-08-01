#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>

void main(void){
    int sd;
    struct sockaddr_in server_addr;
    
    struct hostent *hp;
    
    int num[2], res;
    
    /*se obtiene y rellena la direccion del servicor*/
    bzero((char*)&server_addr, sizeof(server_addr));
    
    hp = gethostbyname("DIRECCION REMOTA");     /*completar con direccion remota*/
    
    if(hp==NULL){
        printf("error en la llamada DIRRECION");
        exit(0);
    }
    memcpy(&(server_addr.sinaddr),hp->h_addr,hp->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4200);
    /*se establece la conxion*/
    if(connect(sd, (struct sockaddr *) &server_addr, sizeof(server_addr))<0){
        perror("Error en la llamada connect");
        exit(0);
    }
    num[0]=5;
    num[1]=2;
    
    write(sd, (char*)num, 2*sizeof(int));
    
    read(sd, (char*)&res, sizeof(int));
    
    close(sd);
    exit(0);
    
}