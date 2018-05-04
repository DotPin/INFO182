#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

/*Algoritmo Lectores y escritores con comparticion de memoria*/
/*Integrantes: Leandro Caloguerea; Diego Rojas*/

sem_t mutex, mx_lec;
int id,x,n_lec,pid,pmem,key,dato, r;

void esc(){
    sem_wait(&mutex);
    dato = dato +2;
    sem_post(&mutex);
}

void lec(){
    sem_wait(&mx_lec);
    n_lec = n_lec + 1;
    if (n_lec == 1) sem_wait(&mutex);
    sem_post(&mx_lec);

    printf("lectura %d\n",dato);

    sem_wait(&mx_lec);
    n_lec = n_lec - 1;
    if(n_lec == 0) sem_post(&mutex);
    sem_post(&mx_lec);
}

void main(){
    
    sem_init(&mutex,0,1);
    sem_init(&mx_lec,0,1);
    
    key=ftok("lec",100);
    id=shmget(key,sizeof(x),IPC_CREAT|0777);
    pmem=shmat(id,NULL,0);
    
    for(int i=0;i<11;i++){
        if(pid=fork() == 0) break;
        if(pid == 0){
            r = rand()%11;
            if (r<5){
                lec();
            }else{
                esc();
            }
        }
    }
    
   
}