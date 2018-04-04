#include<stdio.h>
#include<pthread.h>
#include<sched.h>
#include<unistd.h>
#define MAX_THREADS 10

void priori(int pid){
	struct sched_param param;
	param.sched_priority = 16;
	sched_setparam(pid,&param);
	printf("parámetro prioridad: %i \n",sched_getparam(pid,&param));
}


void func(void){
	int pid;
        printf("thread %d \n", pthread_self());
	printf("system call: %d \n", sched_getscheduler(getpid()));
	pid = getpid();
	priori(pid);
	pthread_exit(0);
}

main(){
        int j;
        pthread_attr_t attr;
        pthread_t thid[MAX_THREADS];
        pthread_attr_init(&attr);
        for(j=0;j < MAX_THREADS;j++)
                pthread_create(&thid[j], &attr, func, NULL);
        for(j=0;j < MAX_THREADS; j++)
		pthread_join(thid[j],NULL);

	while(1){}
}


