#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	pid_t pid;
	string message;
	int n = 0;
	pid = vfork();
	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	if (pid == 0) {
		message = "This is the child\n";
		n++;
		cout<<n<<endl;
		cout<<"my pid = "<<getpid()<<endl;
		cout<<"my parent's pid = "<<getppid()<<endl;
		exit(0);
	} else {
		message = "This is the parent\n";
		cout<<"my pid = "<<getpid()<<endl;
		cout<<"my parent's pid = "<<getppid()<<endl;
		n++;
		cout<<n<<endl;
	}
	return 0;	
}