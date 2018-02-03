#include "stack.h"
#include "link_stack.h"
#include <stdio.h>



void main1()
{
	link_stack s;
	init_link_stack(&s);
}

void main()
{
	printf("%d\n",GetLastResult(ConvertMidToLast("4+(2+1)*2-5")));
}