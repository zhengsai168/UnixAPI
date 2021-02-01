#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

using namespace std;

int main(int argc,char* argv[]){
	struct DIR* dir=NULL;
	dir = opendir(argv[1]);
	struct dirent* file=NULL;
	while( (file = readdir(dir)) != NULL){
		cout<<"file_name "<<file->d_name<<"   ";
		cout<<"file_type "<<file->d_type<<endl;
	}
	
	return 0;	
}