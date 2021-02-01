#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
	int fd;
	char buf[100];
	memset(buf,0,sizeof(buf));
	fd = open("hello", O_RDONLY);
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	lseek(fd, 5, SEEK_CUR);
	off_t x = lseek(fd, 0, SEEK_SET);
	read(fd, buf, 3);
	close(fd);
	return 0;
}