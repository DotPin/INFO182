#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

void inicio1(void);
void inicio2(void);

//compilación gcc main.c productor.c consumidor.c -o tarea -pthread

int pid;
void main(){
    
    printf("Inicia");
    pid = fork();
    
    if(pid == 0){
        inicio2();
        printf("Produce");
    }else{
        inicio1();
        printf("Consume");
    }
}