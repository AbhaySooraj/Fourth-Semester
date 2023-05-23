#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
}p[20],temp;

int n;

void asort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

void bsort()
{
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].bt>p[j].bt)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

void sjf()
{
	float avwt=0,avtat=0;
	p[0].ct=p[0].at+p[0].bt;
	bsort();
	for(int i=0;i<n;i++)
	{
		p[i+1].ct=p[i].ct+p[i+1].bt;
		p[i].tat=p[i].ct-p[i].at;
		avtat=avtat+p[i].tat;
		p[i].wt=p[i].tat-p[i].bt;
		avwt=avwt+p[i].wt;
	}
	
	printf("\nSJF\n\n");
	printf("PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",p[i].pid);
		printf("%d\t",p[i].at);
		printf("%d\t",p[i].bt);
		printf("%d\t",p[i].ct);
		printf("%d\t",p[i].tat);
		printf("%d\t",p[i].wt);
		printf("\n");
	}
	printf(" Average Turn Around Time is %f\n",avtat/n);
	printf(" Average Waiting Time is %f\n",avwt/n);
}

void main()
{
	printf(" Enter the number of process :");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\n Enter Process ID :");
		scanf("%d",&p[i].pid);
		printf(" Enter Arrival Time :"); 
		scanf("%d",&p[i].at);
		printf(" Enter Burst Time :");
		scanf("%d",&p[i].bt);
	}
	sjf();
}	
