#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* Generar un código que lea una sección de memoria y las transformen en buffer cn nmap(1.cpp), e imprimir en pantalla las salidas de cada buffer capturado (2.C)*/

 
void main(){
    struct stat sb;
    off_t len;
    char *p;
    int fd;
    
    fd = open("/home/laboratorio/tree.cpp",O_RDONLY);
    
    p = mmap (0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    }
}
    
