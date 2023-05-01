#include<stdio.h>
#include<stdlib.h>

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
				scanf("%d",&in);
				if(head==NULL)
				{
					head=(struct node *)malloc(sizeof(struct node));
					head->data=in;
					head->next=NULL;
					tail=head;
				}
			
				else
				{
					tail->next=(struct node *)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=in;
					tail->next=NULL;
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
				int x,max,count=0;
				struct node *temp=head;
				printf("\nEnter element to be deleted :");
				scanf("%d",&x);
				
				while(temp!=NULL)
				{
					if(temp->data==x)
					{
						if(count==0)
						{
							max=temp->data;
							head=head->next;
							temp->next=NULL;
							free(temp);
							break;
						}
						
						else
						{
							struct node *del=temp->next;
							temp->next=temp->next->next;
							del->next=NULL;
							free(del);
						}
					}
					else
					{
						temp=temp->next;
						count++;
					}
				}
				
				while(pos!=NULL)
				{
					if(pos->data>max)
					{
						max=pos->data;
					}
				}
				
				while(pos!=NULL)
				{
					if(pos->data>x)
					{
						if(pos->data<max)
						{
							max=pos->data;
						}
					}
				}
				printf("The returned element is %d",max);
				break;
			}
			
			case 5:
			{
				printf("\nExiting");
				exit(0);
			}
			
			default:
			{
				printf("Wrong Option!!!");
			}
		}
	}
}
