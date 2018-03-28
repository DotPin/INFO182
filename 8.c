#include<stdio.h>

void main(){
	int pid;
	for(int i=0;i<3;i++){
		pid=fork();
		//if(pid==0) break;	//evita que la copia de procesos se repita
	}
	while(1);
}
