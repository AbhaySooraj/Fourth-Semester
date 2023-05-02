#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("Child -> ppid %d ,pid %d \n",getppid(),getpid());
		exit(EXIT_SUCCESS);
	}
	
	else if(pid>0)
	{
		printf("Parent -> pid %d \n",getpid());
		printf("Waiting for child process \n");
		wait(NULL);
		printf("Child Finish");
	}
	
	else
	{
		printf("Unable to create \n");
	}
}
