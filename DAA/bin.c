#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void nextfit(int weights[],int cap,int n)
{
	int bin=0;
	int rc=cap;
	for(int i=0;i<n;i++)
	{
		if(weights[i]>rc)
		{
			bin++;
			rc=cap-weights[i];
		}
		else
		{
			rc=rc-weights[i];
		}
		if(rc==0 || i==n-1)
		{
			bin++;
			rc=cap;
		}
	}
	printf(" Number of bins by next fit :%d\n",bin);
}

void firstfit(int weights[],int cap,int n)
{
	int bin=0,j;
	int rc[n];
	for(int i=0;i<n;i++)
	{
		rc[i]=cap;
	}
	
	for(int i=0;i<n;i++)
	{
		for( j=0;j<bin;j++)
		{
			if(weights[i]<=rc[j])
			{
				rc[j]=rc[j]-weights[i];
				break;
			}
		}
		if(j==bin)
		{
			rc[bin]=cap-weights[i];
			bin++;
		}
	}
	printf(" Number of bins by first fit :%d\n",bin);
}

void bestfit(int weights[],int cap,int n)
{
	int bin=0;
	int rc[n];
	for(int i=0;i<n;i++)
	{
		rc[i]=cap;
	}
	for(int i=0;i<n;i++)
	{
		int min=cap+1,index;
		for(int j=0;j<bin;j++)
		{
			if(weights[i]<=rc[j] && rc[j]-weights[i]<min)
			{
				min=rc[j]-weights[i];
				index=j;
			}
		}
		if(min==cap+1)
		{
			rc[bin]=cap-weights[i];
			bin++;
		}
		else
		{
			rc[index]=rc[index]-weights[i];
		}
	}
	printf(" Number of bins by best fit :%d\n",bin);
}


	
void main()
{
	int n,cap,tw,lb;
	printf(" Enter the number of items :");
	scanf("%d",&n);
	int weights[n];
	printf(" Enter the bin capacity :");
	scanf("%d",&cap);
	for( int i=0;i<n;i++)
	{
		printf(" Enter the item %d :",i+1);
		scanf("%d",&weights[i]);
		tw=tw+weights[i];
	}
	lb=ceil(tw/cap);
	nextfit(weights,cap,n);
	firstfit(weights,cap,n);
	bestfit(weights,cap,n);
}
