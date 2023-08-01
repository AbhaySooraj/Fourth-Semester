#include<stdio.h>
#include<stdlib.h>

#define n 5


void init(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
}

void input(int arr[][n])
{
	printf(" Enter adjacency matrix :\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void dfs(int i,int df[],int arr[][n])
{
	printf(" %d ",i);
	df[i]=1;
	for(int j=0;j<n;j++)
	{
		if(arr[i][j]==1 && df[j]==0)
		{
			dfs(j,df,arr);
		}
	}
}


void main()
{
	int graph[n][n],i,option;
	int df[n],bf[n],q[i];
	init(graph);
	input(graph);
	for(i=0;i<n;i++)
	{
		df[i]=0;
	}
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(df[i]==0)
		{
			printf(" Connected component %d:",count);
			dfs(i,df,graph);
			count++;
			printf("\n");
		}
	}
}
				
	
