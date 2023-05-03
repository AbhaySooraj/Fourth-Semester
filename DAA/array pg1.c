#include<stdio.h>
#include<stdlib.h>
#include <time.h>
# define n 1000000

void main()
{
	clock_t start_t, end_t;
	double total_t;
	
	int S[n],x,min,max,pos;
	
	for(int i=0;i<n;i++)
	{
		S[i]=rand()%10000;
	}
	
	printf("\nThe Elements in the array are :");
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",S[i]);
	}
	
	printf("\nEnter element to be deleted :");
	scanf("%d",&x);
	
	
	
	start_t = clock();
	for(int i=0;i<n;i++)
	{
		if(S[i]==x)
		{
			max=S[i];
			pos=i;

		}
		
	}
	for(int j=pos;j<n-1;j++)
	{
		S[j]=S[j+1];
	}
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nTotal time taken by CPU for DELETION: %f\n\n", total_t );

	
	
	
	
	start_t = clock();
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
	
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nTotal time taken by CPU for LARGER ELEMENT: %f\n\n", total_t );
	printf("The returned element is %d",min);
}
