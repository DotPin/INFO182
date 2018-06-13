
#define MAX_BUFFER 1024             /*tamaño buffer*/
#define DATOS_A_PRODUCIR 100000     /*datos a producir*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<semaphore.h>


/*/* Generar un código que lea una sección de memoria y las transformen en buffer cn nmap(1.cpp), e imprimir en pantalla las salidas de cada buffer capturado (2.C)*/
sem_t *elementos;    /*eleementos en el buffer*/
sem_t *huecos; /*huecos en buffer*/



void Productor(int *buffer){        /*lee los datos*/
    int pos = 0;    /*posicion dentro del buffer*/
    int dato;       /*dato a producir*/
    int i;
    
    for(i=0; i< DATOS_A_PRODUCIR; i++){
        dato = i;           /*proucir dato*/
        sem_wait(huecos);   /*un hueco menos*/
        buffer(pos) = i;
        pos = (pos + 1)% MAX_BUFFER;
        sem_post(elementos);    /*un elemento mas*/
        
    }
    return;
    
}


void main(){
     int shd;
     int *buffer;   /*bffer comun*/
     
     
     /*el productor crea el archivo a proyectar*/
     shd = open("/home/laboratorio/Documentos/INFO182/14.cpp", O_CREAT|O_WRONLY, 0700);
     ftruncate(shd, MAX_BUFFER * sizeof(int));
     
     /*proyectar el objeto de memoria compartida en el espacio de direcciones del productor*/
     buffer = (int*)nmap(NULL, MAX_BUFFER * sizeof(int),PROT_WRITE, MAP_SHARED, shd,0);

    if(pid==0){
        lector();
        
    }else{
        escritor();
    }
}


