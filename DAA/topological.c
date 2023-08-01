#include<stdio.h>
#define n 6
int stack[n];
int tos=-1;

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
void push(int z)
{
	tos++;
	stack[tos]=z;

}
void pop()
{
	tos--;
}
void intialize(int arr[][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
}

void dfs(int i, int df[], int arr[][n])
{
	
	for(int j=0;j<n;j++)
	{
		if(arr[i][j]==1 && df[j]==0)
		{
			dfs(j,df,arr);
	
		}
	}
	df[i]=1;
	push(i);
	
}

void main()
{
	int df[n],graph[n][n];
	intialize(graph);
	input(graph);
	for(int i=0;i<n;i++)
	{
		df[i]=0;
	}
	dfs(5,df,graph);
	printf(" The graph is :");
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(df[i]==0)
		{
			printf(" %d ",i);
			count++;
		}
	} 
	for(int i=0;i<n-count;i++)
	{
		printf(" %d ",stack[tos]);
		pop();
	}
	printf("\n");
} 
