#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int fd = 0;
    int ret = 0;
    
    // open() 
    fd = open("/dev/demo", O_RDWR);
    
    if (fd == -1) {
        printf("APP : Can not open Driver \n");
    }else {
        printf("APP : Can open Driver \n");
    }

    // write()
    char writebuf[100] = "This is message : HI Kernel"; // you need to user pointer , not user Array
    // memset(writebuf, 0, sizeof(writebuf));
    ret = write(fd, writebuf, 50);
    if (ret < 0 ) {
        printf("APP : Can not write Driver\n");
    }else {
        printf("APP : Can write Driver %s \n",writebuf);
    }

    // read()
    char readbuf[100];
    // memset(readbuf, 0, sizeof(readbuf));
    ret = read(fd, readbuf, 50);
    if (ret < 0 ) {
        printf("APP : Can not read Driver \n");
    }else {
        printf("APP : Can read Driver, %s\n",readbuf);
    }

    // close() 
    ret = close(fd);
    
    if (ret == -1) {
        printf("APP : Can not close Driver \n");
    }else {
        printf("APP : Can close Driver \n");
    }

    return 0;
}

/*
remember use "sudo ./a.out"
*/
