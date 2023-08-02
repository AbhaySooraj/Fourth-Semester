#include<stdio.h>

struct process
{
	int pid;
	int psize;
};

struct memory
{
	int mid;
	int msize;
	int flag;
	int alloc;
};

void main()
{
	int p,m;
	
	printf(" Enter number of processes :");
	scanf("%d",&p);
	struct process pblocks[p];
	
	printf(" Enter number of memory blocks :");
	scanf("%d",&m);
	struct memory mblocks[m];
	
	for(int i=0;i<p;i++)
	{
		pblocks[i].pid=i;
		printf(" Enter the size of process %d:",i);
		scanf("%d",&pblocks[i].psize);
	}
	
	for(int i=0;i<m;i++)
	{
		mblocks[i].mid=i;
		printf(" Enter the size of memory blocks %d:",i);
		scanf("%d",&mblocks[i].msize);
		mblocks[i].flag=0;
	}
	
	
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(pblocks[i].psize<mblocks[j].msize && mblocks[j].flag==0)
			{
				mblocks[j].alloc=i;
				mblocks[j].flag=1;
				break;
			}
		}
	}
	
	printf(" FIRST FIT \n");
	printf("Block no\t\tBlock size\t\tProcess no\t\tProcess Size\n");
	for(int i=0;i<m;i++)
	{
		if(mblocks[i].flag==1)
		{
			printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",mblocks[i].mid,mblocks[i].msize,mblocks[i].alloc,pblocks[mblocks[i].alloc].psize);
		}
		else
		{
			printf("%d\t\t\t%d\t\t\tAllocation failed\tAllocation failed\n",mblocks[i].mid,mblocks[i].msize);
		}
	}
}

	
	
