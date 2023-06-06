#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,wt,tat,bt,ct;
};
void swap(int i,int j,struct process p[20]){
	struct process temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void atSort(struct process p[20],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].at>p[j].at){
				swap(i,j,p);
			}
		}
	}
}
void pidSort(struct process p[20],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((p[i].at==p[j].at)&&(p[i].pid>p[j].pid)){
				swap(i,j,p);
			}
		}
	}
}
void btSort(struct process p[20],int i,int n,int ict){
	for(int a=i+1;a<n;a++){
		for(int b=a;b<n;b++){
			if((p[0].at<=ict)&&(p[b].at<=ict)){
				if(p[a].bt>p[b].bt){
					swap(a,b,p);
				}
			}
		}
	}
}
void sjf(struct process p[20],int n){
	atSort(p,n);
	pidSort(p,n);
	int ict=p[0].at;
	for(int i=0;i<n;i++){
		if(ict<p[i].at)
			p[i].ct=p[i].at+p[i].bt;
		else
			p[i].ct=ict+p[i].bt;
		ict=p[i].ct;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		btSort(p,i,n,ict);
	}
	
}
void main(){
	struct process p[20],temp;
	int n; 
	float avwt,avtat,twt=0,ttat=0;
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the process ID :");
		scanf("%d",&p[i].pid);
		printf("Enter Arrival Time:");
		scanf("%d",&p[i].at);
		printf("Enter Burst Time:");
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	sjf(p,n);
	
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].pid>p[j].pid)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	
	
	printf("SJF:\n");
	printf("PID\tAT\tBT\tCT\tTAT\tWT\t\n");
	for(int i=0;i<n;i++){
		twt+=p[i].wt;
		ttat+=p[i].tat;
		printf("%d\t",p[i].pid);
		printf("%d\t",p[i].at);
		printf("%d\t",p[i].bt);
		printf("%d\t",p[i].ct);
		printf("%d\t",p[i].tat);
		printf("%d\t",p[i].wt);
		printf("\n");
		printf("\n");
	}
	avwt=twt/n;
	avtat=ttat/n;
	printf("\nAverage WT:%f",avwt);
	printf("\nAverage TAT:%f",avtat);
	printf("\n");
}

