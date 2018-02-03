#include "link_stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void init_link_stack(link_stack *s)
{
	assert(NULL != s);
	s->top = NULL;
	s->count = 0;
}

void destroy_link_stack(link_stack *s)
{
	assert(NULL != s);
	if (isempty_link_stack(s))
	{
		free(s);
		s = NULL;
	}
	else
	{
		LinkStackPtr p = s->top;
		LinkStackPtr q = p;
		while(s->top->next != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}	
	}
}
bool isempty_link_stack(link_stack *s)
{
	assert(NULL != s);
	return s->top == NULL;
}
void push_link_stack(link_stack *s,char val)
{
	assert(NULL != s);
	LinkStackPtr newnode = (LinkStackPtr)malloc(sizeof(StackNode)*1);
	newnode->data = val;
	newnode->next = s->top;
	s->top = newnode;
	s->count++;
}
char pop_link_stack(link_stack *s)
{
	assert(NULL != s);
	if (isempty_link_stack(s))
	{
		printf("Õ»¿Õ£¡\n");
		exit(0);
	}
	else
	{
		LinkStackPtr p = s->top;
		char c = s->top->data;
		s->top = s->top->next;
		free(s->top);
		s->count--;
		return c;
	}
}