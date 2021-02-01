#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int fd;
	char buf[] = "hello";
	fd = open("hello", O_WRONLY | O_CREAT, 0777);
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	write(fd, buf, strlen(buf));
	return 0;
}