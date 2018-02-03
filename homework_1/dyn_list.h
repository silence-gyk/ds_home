#ifndef INIT_STD
#define INIT_STD
#define  INIT_SIZE 10
#define  INCR_SIZE 5
typedef int ELEM_TYPE;
typedef struct  
{
	ELEM_TYPE *date;
	int len;
	int list_size;
}dyn_list;
void init_list(dyn_list *p);
void destroy_list(dyn_list *p);
void clear_list(dyn_list *p);
bool Is_empty(dyn_list *p);
bool Is_full(dyn_list *p);
int get_length(dyn_list *p);
void incr_list(dyn_list *p);
bool insert_head(dyn_list *p,ELEM_TYPE val);
bool insert_tail(dyn_list *p,ELEM_TYPE val);
bool insert_pos(dyn_list *p,int pos,ELEM_TYPE val);
bool delete_val(dyn_list *p,ELEM_TYPE val);
bool delete_pos(dyn_list *p,int pos);
int search(dyn_list *p,ELEM_TYPE key);
void show(dyn_list *p);
bool get_elem(dyn_list *p,int pos,ELEM_TYPE *e);



#endif