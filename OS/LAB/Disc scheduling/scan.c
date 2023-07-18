#include<stdio.h>
#include<stdlib.h>


void main()
{
	int n,q,head,total=0,temp;
	printf(" Enter total number of tracks :");
	scanf("%d",&n);
	
	printf(" Enter total number of requests :");
	scanf("%d",&q);
	int queue[q+1];
	
	for(int i=0;i<q;i++)
	{
		printf(" Enter track number :");
		scanf("%d",&queue[i]);
	}
	queue[q]=n-1;
	
	printf(" Enter current position of head :");
	scanf("%d",&head);
	
	for (int i=0;i<q+1;i++)
	{   
        	for (int j=0;j<q-i;j++)
        	{
        	  	if(queue[j]>queue[j+1])
        		{
            			temp =queue[j];
                		queue[j]=queue[j+1];
                		queue[j+1]=temp;
           		}
        	}
    	}
    	int q1[q],a=0,q2[q],b;
    	for(int i=0;i<q+1;i++)
    	{
    		if(queue[i]<head)
    		{
    			q1[a]=queue[i];
    			a++;
    		}
    		else
    		{
    			q2[b]=queue[i];
    			b++;
    		}
    	}
    	for(int i=0;i<b;i++)
    	{
    		total=total+abs(head-q2[i]);
    		head=q2[i];
    	}
    	for(int i=a;i>=0;i--)
    	{
    		total=total+abs(head-q1[i]);
    		head=q1[i];
    	}
    	printf(" The total number of tack movements using SCAN is %d\n",total);
}
	
    	
    	
    	
