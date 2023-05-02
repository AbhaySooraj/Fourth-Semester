#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void child()
{
	printf(" Hello World ");
}

void parent()
{
	printf(" Main \n");
}

int main()
{
	pid_t pid=fork();
	
	if(pid==0)
	{
		child();
		exit(EXIT_SUCCESS);
	}
	
	else if(pid>0)
	{
		parent();
	}
	
	else
	{
		printf("Unable to create");
	}
	return EXIT_SUCCESS;
}
