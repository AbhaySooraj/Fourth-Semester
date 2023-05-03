#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 1000000



void main()
{
	clock_t start_t, end_t;
	double total_t;
	
	struct node
	{
		int data;
		struct node *next;
	};
	
	struct node *head=NULL,*pos=NULL,*tail=NULL,*temp=NULL;
	
	int ch,in;
	
	for(int i=0;i<n;i++)
	{	
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(struct node));
			head->data=rand()%10000;
			tail=head;
		}
			
		else
		{
			tail->next=(struct node *)malloc(sizeof(struct node));
			tail=tail->next;
			tail->data=rand()%10000;
		}
	}
			
				
	pos=head;
	printf("\n Elements are :");
	while(pos!=NULL)
	{
		printf("%d\t",pos->data);
		pos=pos->next;
	}

				
	int x,max,count=0;
	temp=head;
	printf("\nEnter element to be deleted :");
	scanf("%d",&x);
		
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			max=x;
			break;
		}
		else
		{
			count++;
			temp=temp->next;
		}
	}
	
	
	start_t = clock();
	temp=head;
	if(count==0)
	{
		head=head->next;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		for(int i=0;i<count-1;i++)
		{
			temp=temp->next;
		}
		struct node *del=temp->next;
		temp->next=temp->next->next;
		del->next=NULL;
		free(del);
	}
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nTotal time taken by CPU for DELETION: %f\n\n", total_t );
	
	
	start_t = clock();			
	pos=head;
	while(pos!=NULL)
	{
		if(pos->data>max)
		{
			max=pos->data;
			pos=pos->next;
		}
		else
		{
			pos=pos->next;
		}
		
	}
	
	pos=head;
	while(pos!=NULL)
	{
		if(pos->data>x)
		{
			if(pos->data<max)
			{
				max=pos->data;
				pos=pos->next;
			}
			else
			{
				pos=pos->next;
			}
		}
		else
		{
			pos=pos->next;
		}
	}
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nTotal time taken by CPU for LARGER ELEMENT: %f\n\n", total_t );
	printf("The returned element is %d\n",max);		
}

