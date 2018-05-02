/* Codigo de semaforo en con threads sin condición */


#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

/* unistd.h es para el uso de fork() */


/*compilación debe ser:
$gcc archivo.c -o ejecutable -lpthread 
documentación posible link: http://profesores.elo.utfsm.cl/~agv/elo330/2s06/lectures/POSIX_threads/POSIX_Threads_Synchronization.html*/

//sem_t mutex;
pthread_mutex_t mutex;  //para usar semáforo debe ser en variables de tipo phtread

void *hilo1()   //funcion debe ser de tipo puntero como parámetro pthread_create()
{
     pthread_mutex_lock(&mutex);
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}

void *hilo2()
{
     pthread_mutex_lock(&mutex);
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
   
