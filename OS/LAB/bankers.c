#include<stdio.h>

void main()
{
	int pno;
	int rno;
	int allocation[20][20];
	int max[20][20];
	int avail[20];
	int need[20][20];
	int flag[20];
	int safe[20];
	int l=0;
	
	printf(" Enter no of process :");
	scanf("%d",&pno);
	
	printf(" Enter no of resources :");
	scanf("%d",&rno);
	
	for(int i=0;i<pno;i++)
	{
		printf(" Enter allocation of process %d:",i);
		for(int j=0;j<rno;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	} 
	
	for(int i=0;i<pno;i++)
	{
		printf(" Enter max of process %d :",i);
		for(int j=0;j<rno;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	
	for(int i=0;i<rno;i++)
	{
		printf(" Enter available resource of %d :",i);
		scanf("%d",&avail[i]);
	}
	
	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	
	printf(" The contents of need matrix is :\n");
	for(int i=0;i<pno;i++)
	{
		for(int j=0;j<rno;j++)
		{
			printf(" %d\t",need[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0;i<pno;i++)
	{
		flag[i]=0;
	}
	
	for(int k=0;k<pno;k++)
	{
		for(int i=0;i<pno;i++)
		{
			if(flag[i]==0)
			{
				int f=0;
				for(int j=0;j<rno;j++)
				{
					if(need[i][j]>avail[j])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					safe[l]=i;
					l++;
					for(int m=0;m<rno;m++)
					{
						avail[m]=avail[m]+allocation[i][m];
						flag[i]=1;
					}
				}
			}
		}
	}
	
	int f=1;
	for(int i=0;i<pno;i++)
	{
		if(flag[i]==0)
		{
			f=0;
			printf(" System not safe ");
			break;
		}
	}
	
	if(f==1)
	{
		 printf(" System is safe \n");
		 printf(" Sequence is :");
		 for(int i=0;i<pno;i++)
		 {
		 	printf("%d",safe[i]);
		 	if((i+1)<pno)
		 	{
		 		printf(" -> ");
		 	}
		 }
	}
}
