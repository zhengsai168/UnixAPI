#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char* argv[]){
	struct stat s_buf;
	if(argc<2){
		printf("file !");
		exit(1);
	}
	if(stat(argv[1], &s_buf)<0){
		perror("stat");
		exit(1);
	}
	printf("%s\t%d\n", argv[1], (int)s_buf.st_size);
	if(lstat(argv[1], &s_buf)<0){
		perror("lstat");
		exit(1);
	}
	printf("%s\t%d\n", argv[1], (int)s_buf.st_size);

	return 0;	
}