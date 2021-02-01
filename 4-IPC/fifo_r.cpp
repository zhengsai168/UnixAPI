#include <iostream>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

using namespace std;

void sys_err(char* str){
	perror(str);
	exit(1);
}

void open_fd(int& fd, char* str, mode_t mode){
	fd = open(str, mode);
	if(fd==-1){
		perror("open");
		exit(1);
	}
}

void argc_num(int argc, int num){
	if(argc<num){
		cout<<"need "<<num-1<<"file!"<<endl;
		exit(1);
	}
}

int main(int argc,char* argv[]){
	argc_num(argc, 2);
	int fd;
	char buf[1024];
	open_fd(fd, argv[1], O_RDONLY);
	int len = read(fd, buf, sizeof(buf));
	buf[len] = '\0';
	cout<<buf<<endl;
	close(fd);
    return 0;
}
