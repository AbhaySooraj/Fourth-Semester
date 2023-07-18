#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,q,head,total;
	printf(" Enter total number of tracks :");
	scanf("%d",&n);
	
	printf(" Enter total number of requests :");
	scanf("%d",&q);
	int queue[q];
	
	for(int i=0;i<q;i++)
	{
		printf(" Enter track number :");
		scanf("%d",&queue[i]);
	}
	
	printf(" Enter current position of head :");
	scanf("%d",&head);
	
	for(int i=0;i<q;i++)
	{
		total=total+abs(head-queue[i]);
		head=queue[i];

	}
	printf(" The total number of tack movements using FCFS is %d\n",total);
}
	
