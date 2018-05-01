/* Codigo de semaforo en con threads con condición */
#include<stdlib.h>
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>

/* unistd.h es para el uso de fork() */

int count = 0;


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
     
     //condicion
     while(count == 0) pthread_cond_wait(mutex,1,mutex); //revisar el argumento del cond
          
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}

void hilo2();
{
     sleep(5.0); //Para asegurar el bloqueo
     count = 1;
     pthread_mutex_lock(&mutex);
     
     pthread_cond_signal(&mutex);
     
     /* Sección crítica */
     pthread_mutex_unlock(&mutex);
}
     
