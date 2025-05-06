#include <stdio.h>
#include <stdlib.h>

typedef struct abc
{
	int data;
	struct abc *next;
}node;
node *head = NULL;
node *tail = NULL;

node* creat_node(int val)
{
	node* newnode = (node *) malloc(sizeof(node));
	newnode->data = val;
	newnode->next = NULL;

	return newnode;
}
void insert_beg(int val)
{
	node* newnode = creat_node(val);
	if(head == NULL)
	{
		head = newnode;
		newnode->next = head;
		return;
	}
	node* temp = head;
	while(temp->next != head)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next = head;
	head = newnode;
}
void insert_end(int val)
{
	node* newnode = creat_node(val);
	if(head == NULL)
	{
		head = newnode;
		newnode->next = head;
		return;
	}
	node* temp = head;
	while(temp->next != head)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = head;
}
void delete_beg()
{
	if(head == NULL)
	{
		printf("list empty\n");
		return;
	}
	node* temp = head;
	node* tail = head;
	while(tail->next != head)
	{
		tail = tail->next;
	}
	head = head->next;
	tail = head;
}
void delete_end()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node* temp = head;
	while(temp->next->next != head)
	{
		temp=temp->next;
	}
	temp->next = head;
	temp->next->next = NULL;
	free(temp->next->next);
}
void display()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node* temp = head;
//	printf("Circular Linked List: ");
	do {
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp != head);
	printf("\n");

}
void rev_list()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node* prev = NULL;
	node* cur = head;
	node* next = NULL;
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}
void insert_pos(int val,int pos)
{
	node* newnode = creat_node(val);
	if(pos == 1)
	{
		insert_beg(val);
		return;
	}
	node* temp = head;
	for(int i=1;temp != head && i<pos-1;i++)
	{
		temp = temp->next;
	}
	if(temp == head)
	{
		printf("out of range\n");
		return;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}
void delete_pos(int pos)
{
	if(pos == 1)
	{
		delete_beg();
		return;
	}
	node* temp = head;
	for(int i=pos;temp != head && i<pos - 1;i++)
	{
		temp=temp->next;
	}
	if(temp->next == head)
	{
		delete_end();
		return;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	free(todelete);
}
int enter(int s)
{
	int val=0;
	switch(s)
	{
		case 1:
			{
				printf("enter value\n");
				scanf("%d",&val);
			}
			break;
		case 2:
			{
				printf("enter position\n");
				scanf("%d",&val);
			}
			break;
		default :
			printf("Invalid choice\n");
	}
	return val;
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.insert_beg\n2.insert_end\n3.display\n4.delete_beg\n5.delete_end\n6.insert_pos\n7.delete_pos\n8.revers_list\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int val;
					val = enter(1);
					insert_beg(val);
				}
					break;
			case 2:
				{
					int val;
					val = enter(1);
					insert_end(val);
				}
					break;
			case 3:
					display();
					break;
			case 4:
					delete_beg();
					break;
			case 5:
					delete_end();
					break;
			case 6:
				{
					int val,pos;
					val = enter(1);
					pos = enter(2);
					insert_pos(val, pos);
				}
					break;
			case 7:
				{
					int pos;
					pos = enter(2);
					delete_pos(pos);
				}
					break;
			case 8:
				{
					rev_list();
				}
				        break;
			default:
					printf("Invalid choice\n");
		}
	}
}







