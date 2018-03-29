#include<signal.h>
#include<stdio.h>
#include <stdlib.h>


static void tratar_alarma(void){
        printf("Activada \n");
	exit(1);
}


int main(){
	int a, b,c;
	struct sigaction info;
	a = 1;b=0;
	
	info.sa_handler = tratar_alarma;
	sigemptyset(&info.sa_mask);
	info.sa_flags=0;

	
	sigaction(SIGFPE,&info,NULL);
	c=a/b;
	//if(sigaction(SIGFPE,&info, NULL) != -0){
	//	tratar_alarma();
	//}
	
}
