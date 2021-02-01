#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>

using namespace std;

int main(){
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	cout<< size.ws_row<<"--"<<size.ws_col <<endl;
	return 0;
}