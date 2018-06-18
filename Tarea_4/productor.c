#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define DATOS_A_PRODUCIR 100000
#define NAME "BUFFER"

sem_t *elementos; //elementos en el buffer
sem_t *huecos; //huecos en el buffer
int * buffer; //puntero al buffer de enteros

void productor(int * buffer){
  int dato; //dato a producir
  int posicion = 0; //donde insertar el elemento
  int j;
  for (j = 0; j< DATOS_A_PRODUCIR; j++){
    dato = j;
    sem_wait(huecos); //un hueco -
    buffer[posicion] = dato;
    posicion =(posicion + 1) % MAX_BUFFER; //nueva posicion
    sem_post(elementos); //un elemento mas
  }
  
}

void inicio1(int argc, int argv[]){
  int shd;
  //int *buffer; //buffer comun
  //creacion e inicializacion de semaforos
  huecos = sem_open("HUECOS", O_CREAT, 0700, MAX_BUFFER);
  elementos = sem_open("ELEMENTOS", O_CREAT, 0700, 0);

  //el productor crea el archivo a proyectar
  shd = open(NAME, O_CREAT | O_WRONLY, 0700);
  ftruncate(shd, MAX_BUFFER *sizeof(int));

  //proyectar el objeto de memoria compartida en el espacio de direcciones del productor
  buffer = (int*)(mmap(NULL, MAX_BUFFER *sizeof(int), PROT_WRITE, MAP_SHARED, shd, 0));
  productor(buffer); 

  //desproyeccion del buffer

  munmap(buffer, MAX_BUFFER*sizeof (int));
  close(shd);
  unlink("BUFFER");

  sem_close(huecos);
  sem_close(elementos);
  sem_unlink("HUECOS");
  sem_unlink("ELEMENTOS");
  //exit(0);
}

