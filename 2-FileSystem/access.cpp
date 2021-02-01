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
	cout<<access(name, R_OK);
	cout<<access(name, W_OK);
	cout<<access(name, X_OK);
	cout<<access(name, F_OK);
	
	return 0;	
}