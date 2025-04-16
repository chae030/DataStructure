#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Pos2D { int r; int c; };
typedef struct Pos2D Element;
#include "DequeStruct.h"

#define MAZE_DIM 6
char map[MAZE_DIM][MAZE_DIM] =  {
    { '1', '1', '1', '1', '1', '1' },
    { '0', '0', '0', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};

void push_path(path, loc)
{

}

Element pop_loc (Deque* control)
{
    
}

int main (void)
{
    Deque path, control;
    init_deque(&path);
    init_deque(&control);
    push_loc(&control, 1, 0);

    while(is_empty(&control) == 0)
    {
        system("clear");
        print_maze(&control);
        usleep(50000);

        Element here = pop_loc(&control);

    }

    return 0;
}