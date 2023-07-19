#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>

int n;


int minkey(int key[],bool mstset[])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<n;i++)
	{
		if(mstset[i]==false && key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}

int print(int parent[],int graph[n][n])
{
	int total=0;
	printf(" Edge\t  Weight \n");
	for (int i = 1; i < n; i++)
	{
        	printf("%d - %d \t   %d \n", parent[i], i,graph[i][parent[i]]);
        	total=total+graph[i][parent[i]];
        }
        printf(" The total distance is %d",total);
}

void primMST(int graph[n][n])
{
	int answer[n];
	int key[n];
	bool mstset[n];
	
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	
	key[0]=0;
	
	answer[0]=-1;
	
	for(int count=0;count<n-1;count++)
	{
		int u=minkey(key,mstset);
		mstset[u]=true;
		
		for(int v=0;v<n;v++)
		{
			if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v])
			{
				answer[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	
	print(answer,graph);
}

int main()
{
	printf(" Enter the number of vertices :");
	scanf("%d",&n);
	
	int dmat[n][n];	
	for(int i=0;i<n;i++)
	{
		printf(" Enter the distance from %d :",i+1);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&dmat[i][j]);
		}
	}
	primMST(dmat);
}
