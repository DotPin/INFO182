#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<semaphore.h>
 
 
#define MAX_BUFFER 1024
#define DATOS_A_PRODUCIR 100000
/* programa lectores y escritores */

int cuentalect, cuentaescr;
sem_t mutex, y, z, sescr, slect;
int x=3;        /*DETERMINAMOS QUE HACE DSP CON SALIDAS*/

int shd;
int *buffer;
int b_array[MAX_BUFFER];
int indice=0;

void LEERDATO(){
    printf("lectura");
    
    shd = open("/home/laboratorio/Documentos/INFO182/14.cpp", O_CREAT|O_WRONLY, 0700);
    p = mmap (0, sb.st_size, PROT_READ, MAP_SHARED, shd, 0);
    b_array[indice] = p;    
}

void ESCRIBIRDATO(){
    printf("Escritura");
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
