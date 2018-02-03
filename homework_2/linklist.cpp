#include<stdlib.h>
#include <stdio.h>
#include <assert.h>
#include"linklist.h"
void init_list(node *phead)
{
	assert(phead != NULL);
	phead->date = 0;
	phead->next = NULL;
}
bool is_empty(node *phead)
{
	assert(phead != NULL);
	return phead->next == NULL;
}
int get_length(node *phead)
{
	assert(phead != NULL);
	int length = 0;
	while(phead->next != NULL)
	{
		length++;
		phead = phead->next;
	}
	return length;
}
bool insert_head(node *phead,ElemType val)
{
	assert(phead != NULL);
	node *newnode = (node *)malloc(sizeof(node)*1);
	newnode->date = val;
	newnode->next = phead->next;
	phead->next = newnode;
	return true;
}
bool insert_tail(node *phead,ElemType val)
{
	assert(phead != NULL);
	node *newnode = (node *)malloc(sizeof(node)*1);
	newnode->date = val;
	while (phead->next != NULL)
	{
		phead = phead->next;
	}
	phead->next = newnode;
	newnode->next = NULL;
	return true;
}
void destory_list(node *phead)
{
	assert(phead != NULL);
	node *tmp = NULL;
	while(phead->next != NULL)
	{
		phead = phead->next;
		tmp = phead->next;
		free(phead);
		phead = tmp;
	}
}
void show_list(node *phead)
{
	assert(phead != NULL);
	while(phead->next != NULL)
	{
		phead = phead->next;
		printf("%d ",phead->date);
	}
}
bool delete_val(node *phead,ElemType val)
{
	assert(phead != NULL);
	node *p = phead->next;
	node *q = phead;
	while (p != NULL)
	{
		if (p->date == val)
		{		
			q->next = q->next->next;
			free(p);
			return true;
		}
		q = p;
		p = p->next;
	}
	return false;
}
int get_pos(node *phead,ElemType val)
{
	assert(phead != NULL);
	int pos = 0;
	while (phead->next != NULL)
	{
		pos++;
		phead = phead->next;
		if (phead->date == val)
		{
			return pos;
		}	
	}
	return -1;
}
bool delete_pos(node *phead,int pos)
{
	assert(phead != NULL);
	while (pos-->1)
	{
		phead = phead->next;
	}
	node *tmp = phead->next;
	phead->next = phead->next->next;
	free(tmp);
	return true;
}
bool insert_pos(node *phead,int pos,ElemType val)
{
	assert(phead != NULL);
	node *newnode = (node *)malloc(sizeof(node)*1);
	while(pos-->1)
	{
		phead = phead->next;
	}
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->date = val;
	return true;
}
bool get_val_bypos(node *phead,int pos,ElemType *e)
{
	assert(phead != NULL);
	while(pos--)
	{
		phead = phead->next;
	}
	*e = phead->date;
	return true;
}
bool delete_head(node *phead)
{
	assert(phead != NULL);
	node *tmp = phead->next;
	phead->next = phead->next->next;
	free(tmp);
	return true;
}
bool delete_tail(node *phead)
{
	assert(phead != NULL);
	node *tmp = phead->next;
	node *q = phead;
	while(tmp->next != NULL)
	{
		q = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	q->next = NULL;
	return true;
}




