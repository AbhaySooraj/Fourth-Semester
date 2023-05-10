#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int x,int arr[])
{
	for(int i=0;i<x;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}	

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low,j;

	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
}

void quicksort(int arr[], int low, int high)
{	
	if(low<high)
	{
		int pindex=partition(arr,low,high);
		quicksort(arr,low,pindex-1);
		quicksort(arr,pindex+1,high);
	}
}

void main()
{
	clock_t start_t, end_t;
	double total_bubble,total_quick;
	
	int n;
	printf(" Enter number of elements in array :");
	scanf("%d",&n);
	
	int arrb[n],arrq[n],temp;
	for(int i=0;i<n;i++)
	{
		arrb[i]=rand()%100;
		arrq[i]=rand()%100;
	}
	
	
	
	printf("\n The unsorted array :");
	display(n,arrb);
	
	start_t = clock();
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arrb[j]>arrb[j+1])
			{
				temp=arrb[j];
				arrb[j]=arrb[j+1];
				arrb[j+1]=temp;
			}
		}
	}
	end_t=clock();
	total_bubble=(double)(end_t-start_t)/ CLOCKS_PER_SEC;
	
	start_t = clock();
	quicksort(arrq,0,n);	
	end_t=clock();
	total_quick=(double)(end_t-start_t)/ CLOCKS_PER_SEC;
	
	
	printf("\n The sorted array :");
	display(n,arrb);
	printf("\n Total time taken by bubble sort for %d elements: %f\n\n",n,total_bubble);
	printf("\n Total time taken by quick sort for %d elements: %f\n\n",n,total_quick);
	
	FILE *file1;
	file1=fopen("sort.dat","a+");
	
	fprintf(file1,"%d\t%f\t%f\n",n,total_bubble,total_quick);
	fclose(file1);
	
}
