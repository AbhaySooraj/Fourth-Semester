#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

void main()
{
	int i;
	void *shared_memory;
	char buff[100];
	int shm_id;
	key_t key=ftok("shmfile",65);
	shm_id=shmget(key,1024,0666|IPC_CREAT);
	printf("Key of shared memory is %d",shm_id);
	shared_memory=shmat(shm_id,NULL,0);
	printf(" Enter data :");
	fgets(buff,100,stdin);
	strcpy(shared_memory,buff);
	printf("Data Written is %s",(char *)shared_memory);
} 
