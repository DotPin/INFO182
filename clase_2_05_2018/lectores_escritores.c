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

void lector()
{
	while (true)
	{
		sem_wait (&z);
		sem_wait (&slect);
		sem_wait (&x);
		cuentalect++;
		if (cuentalect == 1) sem_wait (&sescr);
		sem_post (&x);
		sem_post (&slect);
		sem_post (&z);
		LEERDATO();
		sem_wait (&x);
		cuentalect--;
		if (cuentalect == 0) sem_post (&sescr);
		sem_post (&x);
	}
}

void escritor ()
{
	while (true)
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
            suma2();
        }else{
            suma1();
        }
}
