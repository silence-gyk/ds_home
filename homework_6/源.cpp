#include<stdio.h>
#include"queue.h"

void main()
{
	int arr[3][4] = {0};
	int (*p)[4] = arr;
}

void main1()
{
	queue q;
	init_que(&q);
	en_que(&q,1);
	en_que(&q,2);
	en_que(&q,3);
	en_que(&q,4);
	printf("%d\n",get_len(&q));
	printf("%d\n",get_front(&q));
	printf("%d\n",de_queue(&q));
	printf("%d\n",de_queue(&q));
	printf("%d\n",de_queue(&q));
	printf("%d\n",de_queue(&q));
}