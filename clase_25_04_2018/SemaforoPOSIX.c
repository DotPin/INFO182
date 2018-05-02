/* Codigo de semaforo en POSIX */
//Material adicional link:http://www.csc.villanova.edu/~mdamian/threads/posixsem.html


//método de compilacion gcc SemaforoPOSIX.c -o SemaforoPOSIX -lpthread
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<semaphore.h>   //necesario para impementar sem_t
//#include<pthread.h>
#include<unistd.h>

/* unistd.h es para el uso de fork() */

void main()
{
     sem_t mutex;
     int pid, k=0;
     sem_init(&mutex,0,1);
     pid=fork();
     while(k<5){
        printf("pasada %d\n",k);
        printf("ID proceso: %d\n",getpid());
        if(pid == 0){
            
            
            sem_wait(&mutex);
            printf("mutex 1\n");   /* Seccion Crítica */
            sem_post(&mutex);
            
            
        }else{
            
            
            sem_wait(&mutex);
            printf("mutex 2\n");/* Sección Crítica */
            sem_post(&mutex);
            
            
        }
        k++;
     }
}


/* revisar errores de compilación */
