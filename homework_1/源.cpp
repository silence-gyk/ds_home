#include <stdio.h>
#include"dyn_list.h"
void main()
{
	dyn_list ls1;
	init_list(&ls1);
	dyn_list ls2;
	init_list(&ls2);
	for (int i = 1;i < 8;i++)
	{
		insert_tail(&ls1,i);
	}
	for (int i = 4;i < 10;i++)
	{
		insert_tail(&ls2,i);
	}
	show(&ls1);
	show(&ls2);
	//   A
	//for (int i = 0;i < ls1.len;i++)
	//{
	//	for (int j = 0;j < ls2.len;j++)
	//	{
	//		if (ls1.date[i] == ls2.date[j])
	//		{
	//			delete_pos(&ls1,i);
	//		}
	//	}
	//}
	//show(&ls1);
	//   B
	dyn_list ls3;
	init_list(&ls3);
	for (int i = 0;i < ls1.len;i++)
	{
		insert_tail(&ls3,ls1.date[i]);
	}
	show(&ls3);
	for (int i = 0;i < ls2.len;i++)
	{
		for (int j = i;j < ls3.len;j++)
		{
			if (ls2.date[i] >= ls3.date[j] && ls2.date[i] < ls3.date[j+1])
			{
				insert_pos(&ls3,j,ls2.date[i]);
				break;
			}
			if (ls2.date[i] > ls3.date[ls3.len-1])
			{
				insert_pos(&ls3,ls3.len,ls2.date[i]);
			}
		}	
	}
	show(&ls3);
}





//
//void main()
//{
//	dyn_list l;
//	init_list(&l);
//	for (int i = 1;i < 10;i++)
//	{
//		insert_tail(&l,i);
//	}
//	for (int i = 1; i < 10;i++)
//	{
//		insert_head(&l,i);
//	}
//	insert_pos(&l,3,15);
//	delete_val(&l,20);
//	delete_pos(&l,3);
//	int tmp1 = search(&l,5);
//	int tmp2 = search(&l,9);
//	int tmp3 = search(&l,100);
//	printf("%d  %d  %d\n",tmp1,tmp2,tmp3);
//	show(&l);
//}