#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	close(STDOUT_FILENO);
	int fd;
	fd = open("test", O_WRONLY | O_CREAT, 0777);
	cout<<"test"<<endl;
	if(fd == -1){
		perror("hello");
		exit(1);
	}
	close(fd);
	return 0;
}