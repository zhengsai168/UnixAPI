#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>

using namespace std;

int main(int argc,char* argv[]){
	struct stat s_buf;
	if(argc<3){
		printf("file !");
		exit(1);
	}
	const char* name = argv[1];
	const char* new_name = argv[2];
	rename(name,new_name);
	return 0;	
}