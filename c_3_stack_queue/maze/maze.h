#ifndef MAZE
#define MAZE

typedef struct {
	short int vert;
	short int horiz;
} offsets;

#define MAX_DIR 8

enum {N = 0, NE, E, SE, S, SW, W, NW};

#define COL 5
#define ROW 5

void dfs(void);

#endif
