#include<stdio.h>
#include<stdlib.h>

int n,dmat[n][n];

int main()
{
	printf(" Enter the number of vertices :");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf(" Enter the distance from %d",i+1);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&dmat[i][j]);
		}
	}
