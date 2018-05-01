/* Codigo de semaforo en con threads sin condición */
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>

/* unistd.h es para el uso de fork() */

main()
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

void hilo1();
{
     pthread_mutex_lock(&mutex);
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}

void hilo2();
{
     pthread_mutex_lock(&mutex);
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}
     
