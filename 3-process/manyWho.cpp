#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


using namespace std;

int main(void){
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	else if(pid==0){
		cout<<"son"<<endl;
		execlp("who","who",NULL);
	}	
	else {
		cout<<"parent"<<endl;
		execlp("who","who",NULL);
		waitpid(pid,NULL,0);
	}
	return 0;
}