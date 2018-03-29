#include<signal.h>
#include<stdio.h>
#include <stdlib.h>
#include<csignal>


static void exp(void){
	printf("Activada \n");
	exit(1);
	
}

int main(){
	struct sigaction info;
	const int z = 3.12;

	info.sa_handler = tratar_alarma;
        sigemptyset(&info.sa_mask);
        info.sa_flags=0;

	sigaction(SIGSEGV. &info, NULL);
	z = 5;

}
