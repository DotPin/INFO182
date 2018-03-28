//se hace revision de procesos padres e hijos de la cual el proceso hijo no puede enviar señal de detencion al padre por lo que queda en zombie
//

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
        int pid;
        if(fork()==0){
                printf("mi id %i %i\n", getpid(),getppid());            //se genera el proceso hijo
        }else{
                printf("mi id %i %i\n", getpid(),getppid());
        }

}
