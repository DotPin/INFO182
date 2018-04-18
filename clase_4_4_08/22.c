#include<stdio.h>
#include<pthread.h>
#include<sched.h>
#include<unistd.h>


int main(){
    int rc;
    int newprio = 20;
    pthread_t tid;
    pthread_attr_t attr;
    struct sched_param param;

    rc = pthread_attr_init (&attr);
    rc = pthread_attr_getschedparam (&attr, &param);
    (param.sched_priority)++;
    rc = pthread_attr_setschedparam (&attr, &param);

    param.sched_priority = newprio;
}
