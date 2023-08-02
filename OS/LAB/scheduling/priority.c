#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int pri;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}p[20];
int n;

void swap(int i, int j)
{
	struct process temp;
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void asort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=j+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				swap(i,j);
			}
		}
	}
}

void pidsort(int flag)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(flag==0)
			{
				if((p[i].at==p[j].at)&&(p[i].pid>p[j].pid))
				{
					swap(i,j);
				}
			}
			if(flag==1)
			{
				if(p[i].pid>p[j].pid)
				{
					swap(i,j);
				}
			}
		}
	}
}

void prisort(int i, int ict)
{
	for(int a=i+1;a<n;a++)
	{
		for(int b=a+1;b<n;b++)
		{
			if((p[0].at<ict)&&(p[b].at<ict))
			{
				if(p[a].pri>p[b].pri)
				{
					swap(a,b);
				}
			}
		}
	}
}

void priority()
{
	float avtat=0,avwt=0;
	asort();
	pidsort(0);
	int ict=p[0].at;
	for(int i=0;i<n;i++)
	{
		if(ict<p[i].at)
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		else
		{
			p[i].ct=ict+p[i].bt;
		}
		ict=p[i].ct;
		p[i].tat=p[i].ct-p[i].at;
		avtat=avtat+p[i].tat;
		p[i].wt=p[i].tat-p[i].bt;
		avwt=avwt+p[i].wt;
		prisort(i,ict);
	}
	
	pidsort(1);
	printf("\nPRIORITY SCHEDULING\n\n");
	printf("PID\tPR\tAT\tBT\tCT\tTAT\tWT\t\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",p[i].pid);
		printf("%d\t",p[i].pri);
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
		printf(" Enter Priority :");
		scanf("%d",&p[i].pri);
		printf(" Enter Arrival Time :"); 
		scanf("%d",&p[i].at);
		printf(" Enter Burst Time :");
		scanf("%d",&p[i].bt);
	}
	priority();
}			
		
