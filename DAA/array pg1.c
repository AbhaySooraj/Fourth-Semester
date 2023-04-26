#include<stdio.h>
# define n 5

void main()
{
	int S[n]={1,4,10,2,7},x,min,max;
	
	printf("\nThe Elements in the array are :");
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",S[i]);
	}
	
	printf("\nEnter element to be deleted :");
	scanf("%d",&x);
	
	for(int i=0;i<n;i++)
	{
		if(S[i]==x)
		{
			max=S[i];
			S[i]=0;
			break;
		}
	}
	
	
	
	
	for(int i=0;i<n;i++)
	{
		if(S[i]>max)
		{
			max=S[i];
		}
	}
	
	
	
	min=max;	
	for(int i=0;i<n;i++)
	{
		if(S[i]>x)
		{
			if(S[i]<min)
			{
				min=S[i];
			}
		}
	}
	
	
	printf("The returned element is %d",min);
	
	printf("\nThe Elements in the array are :");
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",S[i]);
	}
}
