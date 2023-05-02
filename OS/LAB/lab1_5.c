#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>

void main()
{
	struct stat file;
	stat("lab1_1.c",&file);
	printf(" Size of file lab1_1 is = %ld",file.st_size);
}
