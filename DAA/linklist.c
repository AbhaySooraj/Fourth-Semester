#include<stdio.h>

void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	
	int ch,in;
	
	while(1)
	{
		printf("\n 1:Insert \n 2:Display \n 3:Delete \n 4:Exit ");
		printf("\n Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{		
			case 1:
			{
				printf("Enter the number to be inserted ");
				scanf("%d",&in)
				if(head=NULL)
				{
					head=(struct node *)malloc(sizeof(struct node));
					head->data=in;
					head->next=NULL;
					tail=head;
				}
			
				else
				{
					tail->next=(struct node *)malloc(sizeof(stuct node));
					tail=tail->next;
					tail->data=in;
				}
				break;
			}
			
			case 2:
			{
				
				pos=head;
				printf("\n Elements are :");
				while(pos!=NULL)
				{
					printf("%d\t",pos->data);
					pos=pos->next;
				}
				break;
			}
			
			case 3:
			{
				int x,max;
				printf("\nEnter element to be deleted :");
				scanf("%d",&x);
				
				pos=head;
				while(pos!=NULL)
				{
					if(pos->data==x)
					{
						max=pos->data;
						pos-data=0;
						break;
					}
					else
					{
						pos=pos->next;
						count++;
					}
				}
