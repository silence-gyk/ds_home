#include "dyn_list.h"
#include <stdlib.h>
#include<assert.h>
#include <stdio.h>
void init_list(dyn_list *p)
{
	p->date = (ELEM_TYPE *)malloc(sizeof(ELEM_TYPE)*INIT_SIZE);
	assert(p->date != NULL);
	for (int i = 0;i < INIT_SIZE;i++)
	{
		p->date[i] = 0;
	}
	p->len = 0;
	p->list_size = INIT_SIZE;
}
void destroy_list(dyn_list *p)
{
	assert(p->date != NULL);
	free(p->date);
	p->date = NULL;
	p->len = 0;
}
void clear_list(dyn_list *p)
{
	assert(p->date != NULL);
	for (int i = 0;i < p->len;i++)
	{
		p->date[i] = 0;
	}
	p->len = 0;
}
bool Is_empty(dyn_list *p)
{
	assert(p->date != NULL);
	return p->len == 0;
}
bool Is_full(dyn_list *p)
{
	assert(p->date != NULL);
	return p->len == p->list_size;
}
int get_length(dyn_list *p)
{
	return p->len;
}
void incr_list(dyn_list *p)
{
	assert(p->date != NULL);
	p->date = (ELEM_TYPE *)realloc(p->date,(p->list_size+INCR_SIZE)*sizeof(ELEM_TYPE));
	p->list_size += INCR_SIZE;
}
bool insert_head(dyn_list *p,ELEM_TYPE val)
{
	assert(p->date != NULL);
	if(Is_full(p))
	{
		incr_list(p);
	}
	for (int i = p->len;i > 0;i--)
	{
		p->date[i] = p->date[i-1];
	}
	p->date[0] = val;
	p->len ++;
	return true;
}
bool insert_tail(dyn_list *p,ELEM_TYPE val)
{
	assert(p->date != NULL);
	if (Is_full(p))
	{
		incr_list(p);
	}
	p->date[p->len++] = val;
	return true;
}
bool insert_pos(dyn_list *p,int pos,ELEM_TYPE val)
{
	assert(p->date != NULL);
	if (pos < 0 || pos > p->len)
	{
		return false;
	}
	if(Is_full(p))
	{
		incr_list(p);
	}
	for (int i = p->len;i > pos;i--)
	{
		p->date[i] = p->date[i-1];
	}
	p->date[pos] = val;
	p->len++;
	return true;
}
bool delete_val(dyn_list *p,ELEM_TYPE val)
{
	assert(p->date!=NULL);
	for (int i = 0;i < p->len;i++)
	{
		if (p->date[i] == val)
		{
			for (int j = i;j < p->len;j++)
			{
				p->date[j] = p->date[j+1];
			}
		}
	}
	p->len--;
	return true;
}
bool delete_pos(dyn_list *p,int pos)
{
	assert(p->date != NULL);
	if (pos < 0 || pos >= p->len)
	{
		return false;
	}
	for (int i = pos;i < p->len;i++)
	{
		p->date[i] = p->date[i+1];
	}
	p->len--;
	return true;
}
int search(dyn_list *p,ELEM_TYPE key)
{
	assert(p->date != NULL);
	for (int i = 0;i < p->len;i++)
	{
		if (p->date[i] == key)
		{
			return i;
		}
	}
	return -1;
	
}
void show(dyn_list *p)
{
	assert(p->date != NULL);
	for (int i = 0;i < p->len;i++)
	{
		printf("%d  ",p->date[i]);
	}
	printf("\n");
}
bool get_elem(dyn_list *p,int pos,ELEM_TYPE *e)
{
	assert(p->date != NULL);
	if (pos < 0 || pos >= p->len)
	{
		return false;
	}
	*e = p->date[pos];	
	return true;
}