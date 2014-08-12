#ifndef THREADED_TREE
#define THREADED_TREE

typedef struct threaded_tree *threaded_pointer;
typedef struct {
	short int left_thread;		//left_thread == 1 if left_child is a thread
	threaded_pointer left_child;
	char data;
	short int right_thread;;
	threaded_pointer right_child;
}

void insert_left(threaded_pointer parent, threaded_pointer child);

#endif
