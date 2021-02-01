#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc,char* argv[]){
	struct stat s_buf;
	if(argc<2){
		printf("file !");
		exit(1);
	}
	const char* name = argv[1];
	chmod(name, 0777);
	
	return 0;	
}