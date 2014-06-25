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

#endif
