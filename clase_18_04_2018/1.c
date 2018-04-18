#include<stdio.h>

void main(void){
	int fildes[2];
	char c;

	pipe(fildes);
	//write(fildes[1],&c,1);

	if(fork()==0){
		for(;;){
			read(fildes[0], &c, 1);
			//seccion crítica
			printf("Proceso hijo %d",getpid());
			write(fildes[1], &c, 1);
		}
	}
	else{
		for(;;){
			read(fildes[0], &c, 1);
			//seccion crítica
			printf("Proceso padre %d",getpid());
			write(fildes[1], &c, 1);
		}
	}

}
