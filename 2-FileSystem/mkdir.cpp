#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(int argc,char* argv[]){
	mkdir(argv[1], 0777);
	
	return 0;	
}