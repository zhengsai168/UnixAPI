#include <iostream>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

using namespace std;

int main(){
	int fd[2];
	if(pipe(fd)<0){
		perror("pipe");
		exit(1);
	}
	pid_t pid;
	pid = fork();
	char buf[20];
	memset(buf,0,sizeof(buf));
	if(pid<0){
		perror("fork");
		exit(1);
	}
	else if(pid==0){
		close(fd[1]);
		read(fd[0],buf,20);
		cout<<"son:"<<buf<<endl;
	}
	else {
		close(fd[0]);
		write(fd[1],"hello",5);
		cout<<"father"<<endl;
		wait(NULL);
	}
    return 0;
}
