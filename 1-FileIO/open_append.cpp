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
	char buf[] = "hello";
	fd = open("hello", O_WRONLY|O_CREAT|O_EXCL);
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	write(fd, buf, strlen(buf));
	close(fd);
	return 0;
}