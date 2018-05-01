#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include<mqueue.h>
#include<string.h>
#include<errno.h>

void main(void){

	mqd_t mutex;	//cola de mensajes para sioncronizar acceso a la  seccion crítica
	struct mq_attr attr;	// atrobitos de ña cpña de ,emsajes
	

	attr.mq_maxmsg = 1;	//numero maximo de mensajes
	attr.mq_msgsize = 0;	//tamaño del mensaje
	
	//errno=0;
	mutex = mq_open("\MUTEX", O_CREAT|O_RDWR,0777, &attr);
	//if(errno!=0){	//	comprobación de la llamada a error
	//	printf("error %s",strerrno(errno));
	//}

	if(fork()==0){
		for(;;){
			char c1;
                    	mq_receive(mutex, &c1, 1, 0);	//entrada seccion crítica
                    	putchar(c1);
			
		}

	}else{		//entrada proceso padre
		for(;;){
			char c2='a';
			mq_send(mutex, &c2, 1, 0);

		}
	}


}
