#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

void inicio1(void);
void inicio2(void);

int pid;
void main(){
    pid = fork();
    printf("Inicia");
    if(pid == 0){
        inicio1();
        printf("Produce");
    }else{
        inicio2();
        printf("Consume");
    }
}