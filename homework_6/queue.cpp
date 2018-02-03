#include"queue.h"
#include<assert.h>
#include <stdlib.h>
#include <stdio.h>



void init_que(queue *q)
{
	assert(NULL != q);
	for(int i = 0;i < MAXSIZE;i++)
	{
		q->data[i] = 0;
	}
	q->front = 0;
	q->rear = 0;
}
bool is_empty(queue *q)
{
	assert(NULL != q);
	return q->front == q->rear;
}
bool is_full(queue *q)
{
	assert(NULL != q);
	return get_len(q) == MAXSIZE - 1;
}
int get_len(queue *q)
{
	assert(NULL != q);
	return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}
elem_type get_front(queue *q)
{
	assert(NULL != q);
	if (is_empty(q))
	{
		return -1;
	}
	return q->data[q->front];
}
void en_que(queue *q,elem_type val)
{
	assert(NULL != q);
	if (!is_full(q))
	{
		q->data[q->rear] = val;
		q->rear = (q->rear + 1) % MAXSIZE;
	}
	else
		printf("The queue  is full!\n");
}
elem_type de_queue(queue *q)
{
	assert(NULL != q);
	if (!is_empty(q))
	{
		elem_type tmp = q->data[q->front];
		q->front = (q->front + 1) % MAXSIZE;
		return tmp;
	}
	else
		printf("The queue is empty!\n");
		return -1;
}
