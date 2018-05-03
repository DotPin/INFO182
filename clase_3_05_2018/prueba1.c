#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void main(){
    
    int key,id,pmem,x;
    
    if((key=ftok("home/laboratorio/frases.py",100)==-1)){
        
        printf("archivo existe\n");
        exit();
        
    }
    if((id=shmget(key,sizeof(x),IPC_CREAT|0777))==-1){//se asocia espacio de memoria compartida 
        printf("Memoria compartida\n");
    }
    
    if((pmem=shmat(id,NULL,0))==-1){
    
        printf("no se pudo tomar memoria compartida\n");
    }
    
    
}

