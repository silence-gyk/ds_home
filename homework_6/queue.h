#define MAXSIZE 10
typedef int elem_type;
typedef struct
{
	elem_type data[MAXSIZE];
	int front;
	int rear;
}queue;

void init_que(queue *q);

bool is_empty(queue *q);

bool is_full(queue *q);

int get_len(queue *q);

elem_type get_front(queue *q);

void en_que(queue *q,elem_type val);

elem_type de_queue(queue *q);