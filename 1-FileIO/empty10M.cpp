#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>

using namespace std;

int main(){
	int fd;
	char buf[] = "\0";
	fd = open("10Mempty", O_WRONLY|O_CREAT|O_TRUNC);
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	off_t x = 10240-1;
	lseek(fd, x, SEEK_SET);
	write(fd, buf, 1);
	close(fd);
	return 0;
}