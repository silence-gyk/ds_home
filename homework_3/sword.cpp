#include<stdlib.h>
#include <stdio.h>
#include <assert.h>
#include"linklist.h"
#include "sword.h"


void print_from_end(node *phead)
{
	node *pre_list = RevreseList(phead);
	show_list(pre_list);
}
void delete_node(node *phead,node *pToBeDelete)
{
	assert(phead != NULL);
	assert(pToBeDelete != NULL);
	if (pToBeDelete->next != NULL)
	{
		node *pnode = pToBeDelete->next;
		pToBeDelete->date = pToBeDelete->next->date;
		pToBeDelete->next = pToBeDelete->next->next;
		free(pnode);
		pnode = NULL;
	} 
	else
	{
		node *pnode = phead;
		while (pnode->next != pToBeDelete)
		{
			pnode = pnode->next;
		}
		pnode->next = NULL;
		free(pToBeDelete);
		pToBeDelete = NULL;
	}
}
bool delete_pos_from_end(node *phead,unsigned int k)
{
	if (NULL == phead || k == 0)
	{
		printf("error£¡\n");
		return false;
	}
	node *pAhead = phead;
	node *pBehind = phead;
	while (k-- > 0)
	{
		if (NULL != pAhead->next)
		{
			pAhead = pAhead->next;
		}
		else
		{
			return false;
		}
	}
	while (pAhead != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	delete_node(phead,pBehind);
	return true;
}
node *RevreseList(node *phead)
{
	if (NULL == phead || NULL == phead->next)
	{
		return phead;
	}
	node *pReversrHead = phead;
	node *pNode = phead->next;
	node *pNext_node = pNode->next;
	pNode->next = NULL;
	while (NULL != pNext_node)
	{
		phead = pNode;
		pNode = pNext_node;
		pNext_node = pNext_node->next;
		pNode->next = phead;		
	}
	pReversrHead->next = pNode;
	return pReversrHead;
}
node *MergeList_1(node *phead_1,node *phead_2)
{
	if (NULL == phead_1)
	{
		return phead_2;
	}
	if (NULL == phead_2)
	{
		return phead_1;
	}
	node *pMergeHead = NULL;
	if (phead_1->date < phead_2->date)
	{
		pMergeHead = phead_1;
		pMergeHead->next = MergeList_1(phead_1->next,phead_2);
	}
	else
	{
		pMergeHead = phead_2;
		pMergeHead->next = MergeList_1(phead_1,phead_2->next);
	}
	return pMergeHead;
}
node *MergeList_2(node *phead_1,node *phead_2)
{
	if (NULL == phead_1)
	{
		return phead_2;
	}
	if (NULL == phead_2)
	{
		return phead_1;
	}
	node *pMergeHead = phead_1;
	node *pNode = pMergeHead;
	phead_1 = phead_1->next;
	phead_2 = phead_2->next;
	while (NULL != phead_1 && NULL != phead_2)
	{		
		if (phead_1->date < phead_2->date)
		{
			pNode->next = phead_1;
			phead_1 = phead_1->next;
		} 
		else
		{
			pNode->next = phead_2;
			phead_2 = phead_2->next;
		}
		pNode = pNode->next;
	}
	if (NULL == phead_1)
	{
		pNode->next = phead_2;
	} 
	else if(NULL == phead_2)
	{
		pNode->next = phead_1;
	}
	return pMergeHead;
}
node *FindFirstCommonNode(node *phead_1,node *phead_2)
{
	assert(NULL != phead_1);
	assert(NULL != phead_2);
	int len_1 = get_length(phead_1);
	int len_2 = get_length(phead_2);
	int len_dif = len_1 - len_2;
	node *LongList_head = phead_1;
	node *ShortList_head = phead_2;
	if(len_2 > len_1)
	{
		len_dif = len_2 - len_1;
		LongList_head = phead_2;
		ShortList_head = phead_1;
	}
	while(len_dif--)
	{
		LongList_head = LongList_head->next;
	}
	while(LongList_head != ShortList_head && NULL != LongList_head && NULL != ShortList_head)
	{
		LongList_head = LongList_head->next;
		ShortList_head = ShortList_head->next;
	}
	node *FirstCommonNode = LongList_head;
	return FirstCommonNode;
}