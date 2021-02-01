#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	execlp("./test","test111","1","2",NULL);
	return 0;	
}