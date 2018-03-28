#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
        int kit;
	char *kit2[2];
	kit2[0]="./11";
	kit2[1]="ls";
	kit2[2]=NULL;
        if((kit==execv(kit2[0],kit2))==0){
                printf("hola \n");
        }


}
