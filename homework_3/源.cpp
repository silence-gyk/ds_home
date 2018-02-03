#include"linklist.h"
#include<stdio.h>
#include "sword.h"
void main()
{
	node pHead1;
	node pHead2;
	init_list(&pHead1);
	init_list(&pHead2);
	insert_head(&pHead1,66);
	insert_head(&pHead1,44);
	insert_head(&pHead1,22);
	show_list(&pHead1);
	printf("\n");
	insert_head(&pHead2,99);
	insert_head(&pHead2,88);
	insert_head(&pHead2,33);
	show_list(&pHead2);
	printf("\n");
	node *pHead3 = MergeList_1(&pHead1,&pHead2);
	show_list(pHead3);
	printf("\n");
	node *pHead4 = MergeList_2(&pHead1,&pHead2);
	show_list(pHead4);
	printf("\n");
}
void main1()
{
	node phead;
	init_list(&phead);
	insert_head(&phead,66);
	insert_head(&phead,44);
	insert_head(&phead,22);
	insert_head(&phead,10);
	insert_tail(&phead,77);
	insert_pos(&phead,3,33);
	show_list(&phead);
	printf("\n");
	node *pReList = RevreseList(&phead);
	show_list(pReList);
	printf("\n");
	//delete_node(&phead,(&phead)->next->next);
	//delete_pos_from_end(&phead,1);
	//show_list(&phead);
	//printf("\n");
	//delete_tail(&phead);
	//show_list(&phead);
	//printf("\n");
	//delete_head(&phead);
	//show_list(&phead);
	//printf("\n");
	//delete_val(&phead,77);
	//show_list(&phead);  ///1
	//printf("\n");
	//delete_pos(&phead,2);
	//show_list(&phead);  ///2
	//printf("\n");
	//delete_pos(&phead,1);
	//show_list(&phead);  ///3
	//printf("\n");
	//int i;
	//get_val_bypos(&phead,3,&i);
	//printf("%d\n",i);   ///4
	//delete_head(&phead);
	//show_list(&phead);  ///5
	//printf("%d\n",i);
	//insert_tail(&phead,99);
	//show_list(&phead);  ///6
	//printf("\n");
	//delete_tail(&phead);
	//show_list(&phead);  ///7
	//printf("\n");
	//printf("%d\n",get_length(&phead));
	//printf("%d\n",get_pos(&phead,66));
}

