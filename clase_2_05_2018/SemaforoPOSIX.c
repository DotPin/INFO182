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



int suma1(int x){
    return x+70;
}

int suma2(int x){
    return x*50;
}

int k=2;

void main()
{
     sem_t mutex;
     int pid;
     sem_init(&mutex,0,1);
     pid=fork();
     printf("ID proceso: %d\n",getpid());
     if(pid == 0){
            
            
        sem_wait(&mutex);
        k = suma1(k);
        printf("Suma1: %d\n",k);
        sem_post(&mutex);
            
            
    }else{
            
            
        sem_wait(&mutex);
        k = suma2(k);
        printf("Suma2: %d\n",k);
        sem_post(&mutex);
            
            
    }
        
}


