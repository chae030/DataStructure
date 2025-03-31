#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Pos2D { int r; int c; };
typedef struct Pos2D Element;
// #include "DequeStruct.h"

#define MAZE_DIM 6
char map[MAZE_DIM][MAZE_DIM] =  {
    { '1', '1', '1', '1', '1', '1' },
    { '0', '0', '0', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};

int main (void)
{
    Deque_path, control;
    init_deque(&path);
    init_deque(&control);
    push_loc(&control, 1, 0)

    return 0;
}
// 마저 작성하기