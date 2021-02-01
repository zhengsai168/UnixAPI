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
	long x = fpathconf(STDOUT_FILENO, _PC_NAME_MAX);
	cout<<x<<endl;
	x = pathconf("hello", _PC_PIPE_BUF);
	cout<<x<<endl;
	return 0;	
}