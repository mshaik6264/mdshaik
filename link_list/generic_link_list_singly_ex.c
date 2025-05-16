#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structure for node
typedef struct Node
{
	void *data;
	struct Node *next;
}node;

//structure for Linklist
typedef struct link
{
	node *head;
	size_t dsize;
	void (*printfunc)(void *);
}list;
// initialise the link list
void initlist(list *l, size_t size, void (*printfunc)(void *))
{
	l->head = NULL;
	l->dsize = size;
	l->printfunc = printfunc;
}

node* createnode(void *data, size_t size)
{
	node* newnode = (node *)malloc(sizeof(node));
	newnode->data = malloc(size);
	memcpy(newnode->data, data, size);
	newnode->next = NULL;
	return newnode;
}
void append(list *l, void *data)
{
	node *newnode = createnode(data, l->dsize);
	if(l->head == NULL)
	{
		l->head = newnode;
		return;
	}
	node* temp = l->head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next = newnode;
}
void insert_beg(list *l,void *data)
{
	node *newnode = createnode(data, l->dsize);
	if(l->head == NULL)
	{
		l->head = newnode;
		return;
	}
	newnode->next = l->head;
	l->head = newnode;
}
void display(list *l)
{
	if(l->head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	node *temp = l->head;
	while(temp != NULL)
	{
		l->printfunc(temp->data);
		temp=temp->next;
	}
}
void print_int(void *data)
{
	printf("%d\n",*(int *)data);
}
void print_str(void *data)
{
	printf("%s\n",(char *)data);
}

int main()
{
	char str[]="MohammadShaik";
	list list_int,list_str;
	initlist(&list_int, sizeof(int), print_int);
	initlist(&list_str, sizeof(char) * strlen(str), print_str);

	//char str[]="MohammadShaik";
	int id = 6264;
	append(&list_str, str);
	append(&list_int, &id);
	display(&list_int);
	display(&list_str);

	return 0;
}
