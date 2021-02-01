#include <iostream>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <sys/mman.h>

using namespace std;

void sys_err(char* str){
	perror(str);
	exit(1);
}

void open_fd(int& fd, const char* str, mode_t mode){
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
	argc_num(argc, 1);
	int fd, len;
	int *p;
	char buf[1024] = "hello zs";
	open_fd(fd, "hello", O_RDWR);
	len = lseek(fd, 0, SEEK_END);
	p = (int*)mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd, 0);
	if(p==MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	p[0] = 0x30313233;
	munmap(p, len);
	close(fd);
    return 0;
}
