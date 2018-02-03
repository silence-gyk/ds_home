typedef int ElemType;
typedef struct node
{
	ElemType date;
	struct node *next;
}node;
void init_list(node *phead);
bool is_empty(node *phead);
int get_length(node *phead);
bool insert_head(node *phead,ElemType val);
bool insert_tail(node *phead,ElemType val);
void destory_list(node *phead);
void show_list(node *phead);
bool delete_val(node *phead,ElemType val);
int get_pos(node *phead,ElemType val);
bool delete_pos(node *phead,int pos);
bool insert_pos(node *phead,int pos,ElemType val);
bool get_val_bypos(node *phead,int pos,ElemType *e);
bool delete_head(node *phead);
bool delete_tail(node *phead);

