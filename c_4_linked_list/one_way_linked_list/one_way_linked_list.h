#ifndef ONE_WAY_LINKED_LIST
#define ONE_WAY_LINKED_LIST

typedef struct _list_node *list_pointer;
typedef struct _list_node{
	int data;
	list_pointer link;
} list_node;

#define IS_LIST_EMPTY(ptr) (!(ptr))
#define IS_MEMORY_FULL(ptr) (!(ptr))

void insert(list_pointer *ptr, int data);

void delete(list_pointer *ptr, list_pointer pre);

void print_list(list_pointer ptr);

list_pointer search(list_pointer ptr, int num);

int length(list_pointer ptr);

void interval_delete(list_pointer *ptr);

void merge_list(list_pointer *ptr1, list_pointer *ptr2, list_pointer *ptr3);

void move_rightn(list_pointer *ptr, list_pointer *left, int n);

void move_leftn(list_pointer *ptr, list_pointer *left, int n);

#endif
