#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
}node;

node* creat_node(int value)
{
	node* newnode = (node *)malloc(sizeof(node));
	if(newnode == NULL) return NULL;

	newnode->data = value;
	newnode->next = NULL;

	return newnode;
}
void insert_beg(node** head,int val)
{
	node* newnode = creat_node(val);
	newnode->next = *head;
	*head = newnode;
}
void insert_end(node** head, int val)
{
	node *newnode = creat_node(val);
	if(*head == NULL)
	{
		*head = newnode;
		return;
	}
	node *temp=*head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void insert_pos(node** head, int val, int pos)
{
	if(pos == 1)
	{
		insert_beg(head, val);
		return;
	}
	node* newnode = creat_node(val);
	node* temp = *head;
	for(int i=1;i<pos-1 && temp != NULL ;i++)
		temp=temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
}
void display(node* head)
{
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	node* temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void delete_beg(node** head)
{
	if(*head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node* temp = *head;
	*head=temp->next;
	free(temp);
}
void delete_end(node** head)
{
	if(*head == NULL)
	{
		printf("list is empty\n");
	}
	node* temp=*head;
	while(temp->next->next != NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;

}
void delete_pos(node** head,int pos)
{
	if(pos == 1)
	{
		delete_beg(head);
		return;
	}
	node* temp=*head;
	for(int i=1;i<pos-1 && temp != NULL;i++)
		temp=temp->next;
	node* todelete = temp->next;
	temp->next=temp->next->next;
	free(todelete);
}
void rev_list(node** head)
{
	node* prev = NULL;
	node* cur = *head;
	node* next = NULL;

	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}
int count_node(node** head)
{
	int cnt=0;
	node* temp = *head;
	while(temp != NULL)
	{
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
void insert_midle(node** head, int val)
{
	int count = count_node(head);
	int med = count/2;
	node* newnode = creat_node(val);
	node* temp = *head;
	for(int i=0;i< med - 1 && temp != NULL; i++)
		temp=temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
}


int main()
{
	node* head=NULL;
	int ch;
	while(1)
	{
		printf("\n1.insert_beg\n2.insert_end\n3.insert_position\n4.display\n5.Exit\n6.delete_beg\n7.delete_end\n8.delete_pos\n9.reverse list\n10.No od Nodes\n11.insert_middle\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int val;
					printf("enter value\n");
					scanf("%d",&val);
					insert_beg(&head,val);
				}
				break;
			case 2:
				{
					int val;                                                                                                                                                              printf("enter value\n");                                                                                                                                              scanf("%d",&val);                                                                                                                                                     insert_end(&head,val);
				}
				break;
			case 3:
				{
					int val,pos;
					printf("enter value\n");
					scanf("%d",&val);
					printf("enter position\n");
					scanf("%d",&pos);
					insert_pos(&head,val,pos);
				}
				break;
			case 4:
				display(head);
				break;
			case 5: 
				return 0;
			case 6:
				delete_beg(&head);
				break;
			case 7:
				delete_end(&head);
				break;
			case 8:
				{
					int pos;
					printf("enter position to delete\n");
					scanf("%d",&pos);
					delete_pos(&head,pos);
				}
				break;
			case 9:
				rev_list(&head);
				break;
			case 10:
				
					printf("No of nodes: %d\n",count_node(&head));
					break;
			case 11:
					{
						int val;
						printf("enter value\n");
						scanf("%d",&val);
						insert_midle(&head,val);
					}
					break;



			default:
				printf("Invalid choice\n");
		}
	}
}
