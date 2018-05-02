/* Codigo de semaforo en POSIX */
//Material adicional link:http://www.csc.villanova.edu/~mdamian/threads/posixsem.html


//método de compilacion gcc archivo.c -o ejecutable -lpthread
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<semaphore.h>   //necesario para impementar sem_t
//#include<pthread.h>
#include<unistd.h>

/* unistd.h es para el uso de fork() */

int k=2;
sem_t mutex;

void *suma1(){
    while(1){
        sem_wait(&mutex);
        k = k+5;
        printf("Escribre %d\n",k);
        sem_post(&mutex);
    }
}

void *suma2(){
    while(1){
        sem_wait(&mutex);
        printf("Lee %d\n",k);
        sem_post(&mutex);
    }
}


void main()
{
     
     int pid;
     sem_init(&mutex,0,1);
     pid=fork();
     printf("ID proceso: %d\n",getpid());
     if(pid==0){
         suma2();
     }else{
         suma1();
    }
        
}


