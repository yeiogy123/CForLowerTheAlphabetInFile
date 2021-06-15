#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
int main(int argc, char** argv) {
    int fd, file_num, i;
    char filename[1024], *lower;
    strcpy(filename,argv[1]);
    fd = open(filename,O_RDWR);
    if(fd == 0){
        fprintf(stderr,"not open the file\n");
        exit(0);
    }
    file_num = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    lower = malloc(file_num*sizeof(char));
    read(fd, lower, file_num) ;
    for(i = 0 ; i < file_num+1; i++)
        lower[i] = tolower(lower[i]);
    lseek(fd,0,SEEK_SET);
    write(fd,lower,file_num);
    close(fd);
    return 0;
}
