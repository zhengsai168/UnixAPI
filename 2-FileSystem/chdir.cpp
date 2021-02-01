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
	struct stat s_buf;
	if(argc<2){
		printf("file !");
		exit(1);
	}
	//const char* name = argv[1];
	//chdir(name);
	char new_dir[20];
	//cout<<getcwd(new_dir,20)<<endl;
	//cout<<new_dir<<endl;
	int fd = open("/home/zhengsai/cpp/UnixAPI/2-FileSystem/go", O_RDONLY|O_CREAT, 0777);
	cout<<fd<<endl;
	fchdir(fd);
	cout<<getcwd(new_dir,20)<<endl;
	cout<<new_dir<<endl;
	return 0;	
}