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

void open_fd(int& fd, const char* str, int flags){
	fd = open(str, flags);
	if(fd==-1){
		perror("open");
		exit(1);
	}
}

void open_fd(int& fd, const char* str, int flags, mode_t mode){
	fd = open(str, flags, mode);
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

struct STU{
	int id;
	char name[20];
	char sex;
};


int main(int argc,char* argv[]){
	argc_num(argc, 2);
	int MAPLEN = 1024;
	STU* mm;
	int fd, len;
	open_fd(fd, argv[1], O_RDWR);
	
	lseek(fd, MAPLEN, SEEK_SET);
	write(fd, "\0", 1);

	mm = (STU*)mmap(NULL, MAPLEN, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	int i=1;
	while(1){
		cout<<mm->id<<"---"<<mm->name<<"---"<<mm->sex<<endl;
		sleep(1);
	}
	// 
	//
	munmap(mm, MAPLEN);
    return 0;
}
