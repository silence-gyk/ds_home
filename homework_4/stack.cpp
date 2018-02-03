#include "stack.h"
#include<stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


char *ConvertMidToLast(char *s)
{
	char *last = (char *)malloc(sizeof(char)*50);
	for (int i = 0;i < 50;i++)
	{
		last[i] = '\0';
	}
	int i = 0;
	int flag = 1;
	char_stack charstack;
	init_char_stack(&charstack);
	int len = strlen(s);
	while(len--)
	{
		if(*s >= '0' && *s <= '9')
		{
			last[i] = *s;
			last[(++i)++] = ' ';
			s++;
		}
		else if(isempty_char_stack(&charstack))
		{
			push_char_stack(&charstack,*s);
			s++;
		}
		else if((*s == '*' || *s == '/') && (charstack.str[charstack.top-1] == '+' || charstack .str[charstack.top-1] == '-') && flag)
		{
			push_char_stack(&charstack,*s);
			s++;
		}
		else if ((*s == '+' || *s == '-') && (charstack.str[charstack.top-1] == '*' || charstack .str[charstack.top-1] == '/') && flag)
		{
			last[i] = pop_char_stack(&charstack);
			last[(++i)++] = ' ';
			s++;
		}
		else if((*s == '*' || *s == '/') && (charstack.str[charstack.top-1] == '*' || charstack .str[charstack.top-1] == '*') && flag)
		{
			last[i] = pop_char_stack(&charstack);
			push_char_stack(&charstack,*s);
			last[(++i)++] = ' ';
			s++;
		}
		else if ((*s == '+' || *s == '-') && (charstack.str[charstack.top-1] == '*' || charstack .str[charstack.top-1] == '/') && flag)
		{
			last[i] = pop_char_stack(&charstack);
			push_char_stack(&charstack,*s);
			last[(++i)++] = ' ';
			s++;
		}
		else if (charstack.str[charstack.top-1] == '(')
		{
			push_char_stack(&charstack,*s);
			flag = 0;
			s++;
		}
		else if((*s == '*' || *s == '/') && (charstack.str[charstack.top-1] == '+' || charstack .str[charstack.top-1] == '-') && !flag)
		{
			push_char_stack(&charstack,*s);
			s++;
		}
		else if ((*s == '+' || *s == '-') && (charstack.str[charstack.top-1] == '*' || charstack .str[charstack.top-1] == '/') && !flag)
		{
			last[i] = pop_char_stack(&charstack);
			push_char_stack(&charstack,*s);
			last[(++i)++] = ' ';
			s++;
		}
		else if((*s == '*' || *s == '/') && (charstack.str[charstack.top-1] == '*' || charstack .str[charstack.top-1] == '/') && !flag)
		{
			last[i] = pop_char_stack(&charstack);
			push_char_stack(&charstack,*s);
			last[(++i)++] = ' ';
			s++;
		}
		else if ((*s == '+' || *s == '-') && (charstack.str[charstack.top-1] == '+' || charstack .str[charstack.top-1] == '-') && !flag)
		{
			last[i] = pop_char_stack(&charstack);
			push_char_stack(&charstack,*s);
			last[(++i)++] = ' ';
			s++;
		}
		else if (*s == '(')
		{
			push_char_stack(&charstack,*s);
			flag = 1;
			s++;
		}
		else if (*s == ')')
		{
			while(charstack.str[charstack.top-1] != '(')
			{
				last[i] = pop_char_stack(&charstack);
				last[(++i)++] = ' ';
			}
			pop_char_stack(&charstack);
			s++;
			flag = 1;
		}
	}
	while(!isempty_char_stack(&charstack))
	{
		last[i++] = pop_char_stack(&charstack);
	}
	last[i] = '\0';
	return &last[0];
}
int GetLastResult(char *s)
{
	num_stack numstack;
	init_num_stack(&numstack);
	int len = strlen(s);
	while(len--)
	{
		if (*s == ' ')
		{
			s++;
		}
		else if(*s >= '0' && *s <= '9')
		{
			push_num_stack(&numstack,*s - '0');
			s++;
		}
		else if(*s == '*')
		{
			push_num_stack(&numstack,pop_num_stack(&numstack) * pop_num_stack(&numstack));
			s++;
		}
		else if(*s == '/')
		{
			int i = pop_num_stack(&numstack);
			push_num_stack(&numstack,pop_num_stack(&numstack) / i);
			s++;
		}
		else if(*s == '+')
		{
			push_num_stack(&numstack,pop_num_stack(&numstack) + pop_num_stack(&numstack));
			s++;
		}
		else if(*s == '-')
		{
			int j = pop_num_stack(&numstack);
			push_num_stack(&numstack,pop_num_stack(&numstack) - j);
			s++;
		}
	}
	return numstack.data[numstack.top-1];
}

void init_num_stack(num_stack *s)
{
	s->data = (elem_type *)malloc(sizeof(elem_type)*INITSIZE);
	assert(NULL != s->data);
	for(int i = 0;i < INITSIZE;i++)
	{
		s->data[i] = 0;
	}
	s->top = 0;
	s->stack_size = INITSIZE;
}
void destroy_num_stack(num_stack *s)
{
	assert(NULL != s);
	free(s);
	s = NULL;
}
void incr_num_stack(num_stack *s)
{
	assert(NULL != s);
	s->data = (elem_type *)malloc(sizeof(elem_type)*(s->stack_size+INCRSIZE));
	assert(NULL != s->data);
	s->stack_size += INCRSIZE;
}
bool isfull_num_stack(num_stack *s)
{
	assert(NULL != s);
	return s->top == s->stack_size;
}
bool isempty_num_stack(num_stack *s)
{
	assert(NULL != s);
	return s->top == 0;
}
void push_num_stack(num_stack *s,elem_type val)
{
	assert(NULL != s);
	if (isfull_num_stack(s))
	{
		incr_num_stack(s);
	}
	s->data[s->top++] = val;
}
elem_type pop_num_stack(num_stack *s)
{
	assert(NULL != s);
	if (isempty_num_stack(s))
	{
		printf("Õ»¿Õ£¡\n");
		exit(0);
	}
	else
		return s->data[--s->top];
}




void init_char_stack(char_stack *s)
{
	s->str = (char *)malloc(sizeof(char)*INITSIZE);
	assert(NULL != s->str);
	for (int i = 0;i < INITSIZE;i++)
	{
		s->str[i] = '\0';
	}
	s->top = 0;
	s->stack_size = INITSIZE;
}
void destroy_char_stack(char_stack *s)
{
	assert(NULL != s);
	free(s);
	s = NULL;
}
void incr_char_stack(char_stack *s)
{
	assert(NULL != s);
	s->str = (char *)malloc(sizeof(char)*(s->stack_size+INCRSIZE));
	assert(NULL != s->str);
	s->stack_size += INCRSIZE;
}
bool isfull_char_stack(char_stack *s)
{
	assert(NULL != s);
	return s->top == s->stack_size;
}
bool isempty_char_stack(char_stack *s)
{
	assert(NULL != s);
	return s->top == 0;
}
void push_char_stack(char_stack *s,char val)
{
	assert(NULL != s);
	if (isfull_char_stack(s))
	{
		incr_char_stack(s);
	}
	s->str[s->top++] = val;
}
char pop_char_stack(char_stack *s)
{
	assert(NULL != s);
	if (isempty_char_stack(s))
	{
		printf("Õ»¿Õ£¡\n");
		exit(0);
	}
	else
		return s->str[--s->top];
}