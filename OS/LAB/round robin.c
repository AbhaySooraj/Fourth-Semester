#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int at;
	int bt;
	int bt_print;
	int ct;
	int tat;
	int wt;
	int scheduled;
}p[20];

int n,tq,ttat,twt;
float avtat,avwt;
int tail=-1;
int ready_queue[20];
int time_units=0;

void push(int data)
{
	ready_queue[++tail]=data;
}

int pop()
{
	int data;
	if(tail==-1)
	{
		return -1;
	}
	data=ready_queue[0];
	for(int i=1;i<=tail;i++)
	{
		ready_queue[i-1]=ready_queue[i];
	}
	--tail;
	return data;
}

void display_item(int i)
{
		printf("%d\t",p[i].pid);
		printf("%d\t",p[i].at);
		printf("%d\t",p[i].bt_print);
		printf("%d\t",p[i].ct);
		printf("%d\t",p[i].tat);
		printf("%d\t",p[i].wt);
		printf("\n");
}

void display()
{
	printf("ROUND ROBIN:\n");
	printf("PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	for(int i=0;i<n;i++)
	{
		display_item(i);
	}
	printf("\nAverage WT:%f",avwt);
	printf("\nAverage TAT:%f",avtat);
}

void swap(int i,int j)
{
	struct process temp;
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void pidsort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].pid>p[j+1].at)
			{
				swap(j,j+1);
			}
		}
	}
}

void asort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				swap(j,j+1);
			}
		}
	}
}

int execute(int i)
{
	int time=0;
	if(p[i].bt>tq)
	{
		time=tq;
		time_units+=time;
	}
	else
	{
		time=p[i].bt;
		time_units+=time;
		p[i].ct=time_units;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt_print;
		twt+=p[i].wt;
		ttat+=p[i].tat;
	}
	p[i].bt=p[i].bt-time;
	return time;
}

void add_arrived_tasks(int last_executed)
{
	for(int i=0;i<n;i++)
	{
		if(p[i].bt==0)
		{
			continue;
		}
		
		if(p[i].scheduled==1)
		{
			continue;
		}
		
		if(p[i].at<=time_units)
		{
			push(i);
			p[i].scheduled=1;
		}
	}
}

void rr()
{
	
	int current_task;
	int time;
	asort();
	push(0);
	p[0].scheduled=1;
	
	while(1)
	{
		current_task=pop();
		if(current_task==-1)
		{
			break;
		}
		time=execute(current_task);
		add_arrived_tasks(current_task);
		if(p[current_task].bt>0)
		{
			push(current_task);
		}
	}
	
	avtat=ttat/n;
	avwt=twt/n;
	pidsort();
	printf("\nRR: \n");
	display();
}

int main()
{
	printf(" Enter the number of process :");
	scanf("%d",&n);
	
	printf(" Enter the time quantum :");
	scanf("%d",&tq);
	
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf(" Enter Arrival Time :"); 
		scanf("%d",&p[i].at);
		printf(" Enter Burst Time :");
		scanf("%d",&p[i].bt_print);
		p[i].bt=p[i].bt_print;
	}
	rr();
}	
