#include<stdio.h>
#include<stdlib.h>

void display(int x,float arr[])
{
	for(int i=0;i<x;i++)
	{
		printf("%f\t",arr[i]);
	}
}
void swap(float *x,float *y)
{
	float temp=*x;
	*x=*y;
	*y=temp;
}
void sort(float x[],float y[],float z[],float a[],float b[],int n, int flag)
{
	float  temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(flag==0)    //TO SORT WEIGHT
			{
				if(x[j]<x[j+1])
				{
					temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
					swap(&y[j],&y[j+1]);
					swap(&z[j],&z[j+1]);
					swap(&a[j],&a[j+1]);
					swap(&b[j],&b[j+1]);
				}
			}
			if(flag==1)    //TO SORT SOLUTION TUPLE
			{
				if(x[j]>x[j+1])
				{
					temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
					swap(&y[j],&y[j+1]);
					swap(&z[j],&z[j+1]);
					swap(&a[j],&a[j+1]);
					swap(&b[j],&b[j+1]);
				}
			}
		}
	}
}

		
void main()
{
	int n,weight,u;
	printf(" Enter number of elements :");
	scanf("%d",&n);
	
	float e[n],p[n],w[n],x[n];
	float pw[n];
	
	for(int i=0;i<n;i++)
	{
		x[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		e[i]=i+1;
		printf(" Enter profit of element %d :",i+1);
		scanf("%f",&p[i]);
		printf(" Enter weight of element %d :",i+1);
		scanf("%f",&w[i]);
	}
	printf(" Enter maximum weight :");
	scanf("%d",&weight);
	
	for(int i=0;i<n;i++)
	{
		pw[i]=p[i]/w[i];
	}
	
	sort(pw,p,w,e,x,n,0);
	
	u=weight;
	int i;
	for( i=0;i<n;i++)
	{
		if(w[i]>u)
		{
			break;
		}
		x[i]=1;
		u=u-w[i];
	}
	if(i<=n)
	{
		x[i]=u/w[i];
	}
	
	sort(e,pw,p,w,x,n,1);
	printf(" The solution tuple is \t");

	display(n,x);	
}



