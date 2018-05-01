/* Codigo de semaforo en POSIX */
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>

/* unistd.h es para el uso de fork() */

main()
{
     sem_t mutex;
     int pid;
     sem_init(mutex,0,1);
     pid=fork();
     if(pid == 0){
          sem_wait(&mutex);
          /* Seccion Crítica */
          sem_post(&mutex);
     else{
          sem_wait(&mutex);
          /* Sección Crítica */
          sem_post(&mutex);
          }
     }
}

/* revisar errores de compilación */
