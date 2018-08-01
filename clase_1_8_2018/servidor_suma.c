#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>

void main(void){
    struct sockaddr_in server_addr, client_addr;    /*direcciones IP:puerto*/
    int sd, sc;
    int size;
    int num[2],res;
    
    sd = socket(AF_INET, SOCK_STREAM,0);    //socket(AF_INET (dominio internet) | AF_UNIX(dominio unix) , SOCK_STREAM (TCP)|SOCK_DGRAM(UDP) ,0 (protocolo) );
    /*asigna direccion al socker*/
    
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(4200);
    bind(sd,&server_addr,sizeof(server_addr));      /*(socket asociado, direccion del socket, longitud del socket);*/
    listen(sd,5);
    size = sizeof(client_addr);
    while(1){
        printf("esperando conexion\n");
        sc = accept (sd, (struct sockaddr *)&client_addr, &size);
        if (sc<0){
            break;
        }
        
        /*recibe peticion, dos numeros enteros*/
        
        read(sc, (char*)num, 2*sizeof(int)));   
        res = num[0] + num[1]; /*obtiene resultado*/
        
        /*envia el resultado y cierra la conexion*/
        
        write(sc, (char*)&res,sizeof(int));
        close(sc);
    }
    printf("error en accept\n");
    close(sd);
    exit(0)
}