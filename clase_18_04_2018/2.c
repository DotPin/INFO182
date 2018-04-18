#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include<mqueue.h>

void main(void){

	mqd_t mutex;	//cola de mensajes para sioncronizar acceso a la  seccion crítica
	struct mq_attr attr;	// atrobitos de ña cpña de ,emsajes
	char c;		// caracter de para sincronizar

	attr.mq_maxmsg = 1;	//numero maximo de mensajes
	attr.mq_msgsize = 0;	//tamaño del mensaje

	mutex = mq_open("MUTEX", O_CREAT|O_RDWR,0777, &attr);

	if(fork()==0){
		for(;;){
			mq_receive(mutex, &c, 1, 0);	//entrada seccion crítica
			mq_send(mutex, &c, 1,0 );	//salida seccion crítica
		}

	}else{		//entrada proceso padre
		for(;;){
			mq_receive(mutex, &c, 1, 0);
			mq_send(mutex, &c, 1, 0);

		}
	}


}
