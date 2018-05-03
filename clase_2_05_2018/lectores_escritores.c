#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<semaphore.h>
 
/* programa lectores y escritores */

int cuentalect, cuentaescr;
sem_t mutex, y, z, sescr, slect;
int x=3;

void LEERDATO(){
    printf("lectura de x: %d\n",x);
}

void ESCRIBIRDATO(){
    printf("Escritura de x\n");
    x = 3;
}

void lector()
{
	while (1)
	{
		sem_wait (&z);
		sem_wait (&slect);
		sem_wait (&y);
		cuentalect++;
		if (cuentalect == 1) sem_wait (&sescr);
		sem_post (&y);
		sem_post (&slect);
		sem_post (&z);
		LEERDATO();
		sem_wait (&y);
		cuentalect--;
		if (cuentalect == 0) sem_post (&sescr);
		sem_post (&y);
	}
}

void escritor ()
{
	while (1)
	{
		sem_wait (&y);
		cuentaescr++;
		if (cuentaescr == 1) sem_wait (&slect);
                sem_post (&y);
		sem_wait (&sescr);
		ESCRIBIRDATO();
		sem_post (&sescr);
		sem_wait (&y);
		cuentaescr--;
		if (cuentaescr == 0) sem_post (&slect);
                sem_post (&y);
	}
}

void main()
{
	cuentalect = cuentaescr = 0;
	int pid;
        sem_init(&mutex,0,1);
        sem_init(&y,0,1);
        sem_init(&z,0,1);
        sem_init(&sescr,0,1);
        sem_init(&slect,0,1);
        pid=fork();
        printf("ID proceso: %d\n",getpid());
        if(pid==0){
            lector();
        }else{
            escritor();
        }
}
