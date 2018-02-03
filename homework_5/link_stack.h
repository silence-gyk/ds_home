typedef struct stack_node
{
	char data;
	struct stack_node *next;
}StackNode,* LinkStackPtr;
typedef struct link_stack
{
	LinkStackPtr top;
	int count;
}link_stack;

void init_link_stack(link_stack *s);

void destroy_link_stack(link_stack *s);

bool isempty_link_stack(link_stack *s);

void push_link_stack(link_stack *s,char val);

char pop_link_stack(link_stack *s);