#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
	struct list *prev;
}node;

node *head = NULL; //head is global 

node* creat_node(int val)
{
	node* newnode = (node *)malloc(sizeof(node));
	if(newnode == NULL)
	{
		printf("fail to allocate memory\n");
		return NULL;
	}
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;

	return newnode;
}
void insert_beg(int val)
{
	node* newnode = creat_node(val);
	if(head == NULL)
	{
		head = newnode;
		printf("head is NULL\n");
		return;
	}

	newnode->next = head;
	head->prev = newnode;
	head = newnode;
}
void insert_end(int val)
{
	node* newnode = creat_node(val);
	if(head == NULL)
	{
		head = newnode;
		printf("head is NULL\n");
		return;
	}
	node* temp = head;
	while(temp->next != 0)
	{
		temp=temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
}
void print()
{
	node *temp=head;
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int enterval()
{
	int val;
	printf("Enter the value\n");
	scanf("%d",&val);
	return val;
}
void delete_beg()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(head->next == NULL)
	{
		head = NULL;
		free(head);
		return;
	}
	node* temp = head;
	head=head->next;
	head->prev=head->prev->prev;
	free(temp);
}
void delete_end()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(head->next == NULL)
	{
		head = NULL;
		free(head);
		return;
	}
	node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->prev = NULL;
	free(temp);
}
void insert_pos(int val,int pos)
{
	if(pos == 1)
	{
		insert_beg(val);
		return;
	}
	node *temp = head;
	for(int i=1;temp!=NULL && i<pos-1 ;i++)
	{
		//printf("%d.temp->next\n",i);
		temp=temp->next;
	}
	if(temp == NULL)
	{
		printf("pos is out of range so adding in last\n");
		insert_end(val);
		return;
	}
	node *newnode = creat_node(val);
	newnode->next = temp->next;
	newnode->prev = temp;
	if(temp->next != NULL)
	{
		temp->next->prev = newnode;
	}
	temp->next = newnode;
}
void delete_pos(int pos)
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(pos == 1)
	{
		delete_beg();
		return;
	}
	node *temp = head;
	for(int i=1;temp != NULL && i<pos;i++)
	{
		temp = temp->next;
	}
	if(temp == NULL)
	{
		printf("outof the range\n");	
		return;
	}
	if(temp->prev != NULL)
	{
		temp->prev->next = temp->next;
	}
	if(temp->next != NULL)
	{
		temp->next->prev=temp->prev;
	}
	free(temp);
}
void rev_list()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node *cur=head, *temp=NULL;
	while(cur != NULL)
	{
		temp = cur->prev;
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}
	if(temp != NULL) head = temp->prev;
	
}
void print_mid()
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	node *slow = head, *fast = head;
	while(fast != NULL && fast->next !=NULL)
	{
		slow = slow->next; //one step move
		fast = fast->next->next; //two steps move
	}
	printf("mid node: %d\n",slow->data);
}
void detect_loop()
{
	if(head == NULL)
	{
		printf("empty\n");
		return;
	}
	node* slow = head, *fast = head;
	while(fast != 0 && fast->next != 0)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			printf("loop is detected\n");
			return;
		}
	}
	printf("loop is not detected\n");
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.insert_beg\n2.insert_end\n3.display\n4.delete_beg\n5.delete_end\n6.insert_position\n7.delet_position\n8.reverse_list\n9.midle_node\n10.detect loop\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int val;
					val = enterval();
					insert_beg(val);
				}break;
			case 2:
				{
					int val;
					val = enterval();
					insert_end(val);
				}
				break;
			case 3:
				print();
				break;
			case 4:
				delete_beg();
				break;
			case 5:
				delete_end();
				break;
			case 6:
				{
					int val=enterval();
					int pos;
					printf("enter position to store\n");
					scanf("%d",&pos);
					insert_pos(val,pos);
				}
				break;
			case 7:
				int pos;
				printf("enter pos to delete\n");
				scanf("%d",&pos);
				delete_pos(pos);
				break;
			case 8:
				rev_list();
				break;
			case 9:
				print_mid();
				break;
			case 10:
				detect_loop();
				break;

			default:
				printf("Invalid choice\n");
 
		}
	}
	return 0;
}
	

