/* Codigo de semaforo en con threads condicionado*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
#include<pthread.h>


/* unistd.h es para el uso de fork() */


/*compilación debe ser:
$gcc archivo.c -o ejecutable -lpthread 
 apoyo material link: http://profesores.elo.utfsm.cl/~agv/elo330/2s09/lectures/POSIX_Threads_ConditionVariables.html*/


int count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *hilo1()//funciones hilo deben ser punteros
{
     pthread_mutex_lock(&mutex);
     
     //condicion
     while(count == 0) pthread_cond_wait(&cond,&mutex); 
          
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}

void *hilo2()
{
     sleep(5.0); //Para asegurar el bloqueo
     count = 1;
     pthread_mutex_lock(&mutex);
     
     pthread_cond_signal(&cond);
     
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}
     


void main()
{
     pthread_t th1, th2;
     pthread_mutex_init(&mutex, NULL);
     
     //creacionThread(puntero|atributos|nombre|argumentos para el void hilo()) 
     pthread_create(&th1, NULL, hilo1, NULL); 
     pthread_create(&th2, NULL, hilo2, NULL);
     
     pthread_join(th1, NULL);
     pthread_join(th1, NULL);
     
     pthread_mutex_destroy(&mutex);
}


