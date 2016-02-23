#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*struct node*/
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

node *head = NULL;

int list_create();
int list_add(int data);
int list_destory();
int list_reversal();

int list_create()
{
	head = NULL;
	return 0;
}

int list_add(int data)
{
	node *p;
	p = malloc(sizeof(node));
	if(p == NULL)
		return -1;
	p->data = data;
	p->next = NULL;
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	return 0;
}

int list_destory()
{
	node *p;
	if(head == NULL)
		return 0;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return 0;
}

int list_reversal()
{
	if(head == NULL)
		return -1;
	node *pre = NULL;
	node *curr = NULL;
	node *next = NULL;

	curr = head;
	for(;curr->next != NULL;)
	{
		next = curr->next;
		curr->next = pre;

		pre = curr;
		curr = next;
	}
	curr->next = pre;
	head = curr;

	return 0;
}

void list_show()
{
	node* p = head;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int i;
	list_create();
	for(i = 0;i < 20;i++)
	{
		list_add(i);
	}

	list_show();

	list_reversal();

	list_show();

	return 1;
}
