#include<stdio.h>

void main(){
        int pid;
        pid = fork();           //fork es una llamada al sistema para crear un proceso clon del actual
        if(pid==0){
                printf("soy el hijo\n");
		while(1);
        }
        else{
                printf("soy tu padre\n");
		while(1);		//revisando hilo de proceso de la mem principal
        }
}
