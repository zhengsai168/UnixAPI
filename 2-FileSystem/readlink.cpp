#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <cstring>

#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>

using namespace std;

int main(int argc,char* argv[]){
	struct stat s_buf;
	if(argc<2){
		printf("file !");
		exit(1);
	}
	const char* name = argv[1];
	char buf[10];
	memset(buf,0,sizeof(buf));
	readlink(name,buf,10);
	cout<<buf<<endl;
	return 0;	
}