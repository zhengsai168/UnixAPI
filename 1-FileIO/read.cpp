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
	char buf[10];
	fd = open("hello", O_RDONLY);
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	int len = read(fd, buf, strlen(buf));
	buf[len] = '\0';
	cout<<buf<<endl;
	close(fd);
	return 0;
}