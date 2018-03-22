#include<stdio.h>

int main(){
	int x,*p;
	p = malloc(sizeof(x));	//instruccion perteneciente kernel con nmap del strace
	*p = 10;		//instruccion perteneciente a modo usuario
	printf("el valor de x es %i\n",x);	//instruccion pertenenciente a modo kernel
}
