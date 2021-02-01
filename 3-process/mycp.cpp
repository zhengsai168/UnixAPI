#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


using namespace std;

int main(int argc, char *argv[]){
	if(argc<3){
		cout<<"file!"<<endl;
		exit(1);
	}
	int fd_src;
	int fd_dest;
	if( (fd_src = open(argv[1], O_RDONLY)) ==-1 ){
		perror("open src");
		exit(1);
	}
	if( (fd_dest = open(argv[2], O_WRONLY|O_CREAT)) ==-1 ){
		perror("open dest");
		exit(1);
	}
	char buf[1000];
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	else if(pid==0){
		size_t len;
		while((len= read(fd_src, buf, sizeof(buf)))){
			write(fd_dest, buf, len);
			cout<<"son: "<<len<<endl;
		}

	}
	else{
		size_t len;
		while((len= read(fd_src, buf, sizeof(buf)))){
			write(fd_dest, buf, len);
			cout<<"parent"<<len<<endl;
		}
		int status;
		waitpid(pid,&status,0);
		cout<<"son status:  "<<status<<endl;
	}
	cout<<"success!"<<endl;
	return 0;
}