typedef int elem_type;
#define INITSIZE 20
#define INCRSIZE 5

typedef struct
{
	elem_type *data;
	int top;
	int stack_size;
}num_stack;
typedef struct  
{
	char *str;
	int top;
	int stack_size;
}char_stack;

char *ConvertMidToLast(char *s);
int GetLastResult(char *s);




void init_num_stack(num_stack *s);
void destroy_num_stack(num_stack *s);
void incr_num_stack(num_stack );
bool isfull_num_stack(num_stack );
bool isempty_num_stack(num_stack );
void push_num_stack(num_stack *s,elem_type val);
elem_type pop_num_stack(num_stack *s);

void init_char_stack(char_stack *s);
void destroy_char_stack(char_stack *s);
void incr_char_stack(char_stack *s);
bool isfull_char_stack(char_stack *s);
bool isempty_char_stack(char_stack *s);
void push_char_stack(char_stack *s,char val);
char pop_char_stack(char_stack *s);