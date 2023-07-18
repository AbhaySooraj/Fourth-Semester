#include<stdio.h>
#include<stdlib.h>


void main()
{
	int n,q,head,total=0;
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
		int min=n,d,index;
		for(int j=0;j<q;j++)
		{
			d=abs(head-queue[j]);
			if(min>d)
			{
				min=d;
				index=j;
			}
		}
		total=total+abs(head-queue[index]);
		head=queue[index];
		queue[index]=n;

	}
	printf(" The total number of tack movements using SSTF is %d\n",total);
}
	
