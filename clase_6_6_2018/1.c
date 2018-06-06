#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
    struct stat sb;
    off_t len;
    char *p;
    int fd;
    
    fd = open("/home/laboratorio/tree.cpp",O_RDONLY);
    
    if (fd== -1){
        perror("open");
        printf("No encontrado\n");
    }
    else{ 
        printf("ok file\n");
        printf("id file: %d\n",fd);
    }
    
    if (fstat(fd, &sb)== -1){
        perror("fstat");
        printf("no hay descriptor del archivo \n");
      
    }else{
        printf("ok descriptor\n");
        printf("descriptor id: %d\n",fstat(fd, &sb));
    }
    
    if (!S_ISREG (sb.st_mode)) {
                fprintf (stderr, "%s is not a file\n","/home/laboratorio/tree.cpp" );
    }else{
        printf("ok PATH\n");
        printf("PATH PROTECTION: %d\n",S_ISREG (sb.st_mode));
    }

    p = mmap (0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    if (p == MAP_FAILED) {
                perror ("mmap");
                printf("Archivo no ha sido mapeado\n");
    }else{
        printf("ok MAPPING\n");
        //printf("MAP id: %s\n",p);
    }
}
    