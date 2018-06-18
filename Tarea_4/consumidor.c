#include <sys/mman.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<unistd.h>


#define MAX_BUFFER 1024
#define DATOS_A_PRODUCIR 100000

sem_t *huecos;
sem_t *elementos;
int *buffer; /* buffer de números enteros */

/*código del proceso productor */
  void consumidor (){
    int dato;
    /*dato a consumir */
    int posicion = 0; /* posición que indica el elemento a extraer */
    int j;
    for (j = 0; j<DATOS_A_PRODUCIR; j++){
      
      sem_wait(elementos); /* un elemento menos */
      dato = buffer[posicion];
      posicion = (posicion + 1) % MAX_BUFFER; /* nueva posición */
      sem_post (huecos); /* un hueco más)*/
      printf("Consume %d \n", dato); /*consumir dato*/    
    }
    
  }

void inicio2(void){
  int shd;
  /* se abren los semáforos */
  huecos = sem_open("HUECOS", 0);
  elementos = sem_open("ELEMENTOS", 0);

  /*se abre el segmento de memoria compartida utilizado como buffer circular */
  shd = open("BUFFER", O_RDONLY);

  buffer = (int *)(mmap(NULL,MAX_BUFFER*sizeof(int), PROT_READ,MAP_SHARED, shd, 0));

  consumidor(); //el compilador si no se le indica espera un int o.o
  
  munmap(buffer, MAX_BUFFER*sizeof (int));
  close(shd);

  /*se cierran semáforos */
  sem_close (huecos);
  sem_close(elementos);
  exit(0);
}

