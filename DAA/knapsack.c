#include<stdio.h>

struct item
{
	int id;
	float p;
	float w;
	float pw;
	float a;
};

void main()
{
	int n,max;
	printf(" Enter the number of items :");
	scanf("%d",&n);
	struct item arr[n];
	
	printf(" Enter the max weight :");
	scanf("%d",&max);
	
	for(int i=0;i<n;i++)
	{
		arr[i].id=i+1;
		
		printf(" Enter profit of item %d :",i+1);
		scanf("%f",&arr[i].p);
		
		printf(" Enter weight of item %d :",i+1);
		scanf("%f",&arr[i].w);
		
		arr[i].pw=arr[i].p/arr[i].w;
		
		arr[i].a=0;
	} 
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j].pw<arr[j+1].pw)
			{
				struct item temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	int u=max,k=0;
	float profit;
	for(k=0;k<n;k++)
	{
		if(arr[k].w>u)
		{
			break;
		}
		u=u-arr[k].w;
		profit=profit+arr[k].p;
		arr[k].a=1;
	}
	
	if(k<=n)
	{
		arr[k].a=u/arr[k].w;
		profit=profit+arr[k].p*(u/arr[k].w);
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j].id>arr[j+1].id)
			{
				struct item temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	printf(" The max profit is :%f",profit);
	printf("\n The solution tuple is :");
	for(int i=0;i<n;i++)
	{
		printf(" %f ",arr[i].a);
	}
}
