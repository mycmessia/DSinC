#ifndef THREADED_TREE
#define THREADED_TREE

typedef struct threaded_tree *threaded_pointer;
typedef struct {
	short int left_thread;		/* 1 if left_child is a thread */
	threaded_pointer left_child;
	char data;
	short int right_thread;;
	threaded_pointer right_child;
}

/* find the inorder successor of thread_pointer tree *//
threaded_pointer insucc(threaded_pointer tree);
threaded_pointer presucc(threaded_pointer tree);
threaded_pointer postsucc(threaded_pointer tree);

void tinorder(threaded_pointer tree);
void tpreorder(threaded_pointer tree);
void tpostorder(thteaded_pointer tree);

void insert_right(threaded_pointer parent, threaded_pointer child);

void insert_left(threaded_pointer parent, threaded_pointer child);

#endif
