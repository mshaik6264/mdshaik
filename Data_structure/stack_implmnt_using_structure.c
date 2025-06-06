#include <stdio.h>
#include <stdlib.h>
#define max_size 5
typedef struct st
{
	int *data;
	int top;
}stack;

void init_stack(stack *st)
{
	st->data = (int *)malloc(max_size);
	st->top = - 1;
}

void push(stack *st, int val)
{
	if(st->top == max_size - 1)
	{
		printf("Stack is Full please do pop\n");
		return;
	}
	st->top++;
	st->data[st->top] = val;
}
void pop(stack *st)
{
	if(st->top == -1)
	{
		printf("Stack is Empty please do push\n");
		return;
	}
	int poped = st->data[st->top];
	st->top--;
	printf("poped item is:%d\n",poped);
}
void display(stack *st)
{
	if(st->top == -1)
	{
		printf("Stack is Empty\n");
		return;
	}
	for(int i=(st->top);i>=0;i--)
		printf("%d ",st->data[i]);
	printf("\n");
}
int main()
{
	stack s1;
	int c;
	init_stack(&s1);
	while(1)
	{
		printf("1.push\n2.pop\n3.display\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				int val;
				printf("enter data push to stack\n");
				scanf("%d",&val);
				push(&s1, val);
				break;
			case 2:
				pop(&s1);
				break;
			case 3:
				display(&s1);
				break;
			default:
				printf("Invalid number\n");
		}
	}
}


