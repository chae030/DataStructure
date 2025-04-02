#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void push_path(Deque *path, Element loc)
{
    while(!is_empty(path))
    {
        Element prev = get_rear(path);
        if ((prev.c == loc.c && abs(prev.r - loc.r) == 1) || (prev.r == loc.r && abs(prev.c - loc.c) == 1))
        {
            add_rear(path, loc);
            return;
        }
        else
        {
            delete_rear(path);
        }
    }
    add_rear(path, loc);
}

void print_path(Deque * path)
{
    Element pos = delete_front(path);
    printf("(%d, %d)", pos.r, pos.c);
    while (!is_empty(path))
    {
        pos = delete_front(path);
        printf("->(%d, %d)", pos.r, pos.c);
    }
    printf("\n");
}

void push_loc(Deque * control, int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_DIM || c >= MAZE_DIM) return;
    if (map[r][c] != '0' && map[r][c] != 'x') return;
    Element pos = {r, c};
    add_rear(control, pos);
}

Element pop_loc (Deque * control)
{
    return delete_rear(control);
    // return delete_front();
}

void print_maze(Deque *control)
{
    Element here = get_rear(control);
    for (int r = 0; r < MAZE_DIM; r++)
    {
        for (int c = 0; c < MAZE_DIM; c++)
        {
            if (here.r == r && here.c == c) printf("@");
            else printf("%c", map[r][c]);
        }
        printf("\n");
    }
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
        int c = here.c;
        int r = here.r;
        push_path(&path, here);
        if (map[r][c] == 'x')
        {
            printf("\n미로 탈출 경로: ");
            print_path(&path);
            return 0;
        }
        else{
            map[r][c] = '.';
            push_loc(&control, r-1, c);
            push_loc(&control, r+1, c);
            push_loc(&control, r, c-1);
            push_loc(&control, r, c+1);
        }
    }
    printf("\n미로 탈출 실패\n");
    return 0;
}
