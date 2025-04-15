#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Waiting
{
    int id;
    int nperson;
    char info[32];
};
typedef struct Waiting Element;
#include "CircularQueue.h"

int main (void)
{
    Element waiting[4] = {
        {12, 2, "010-xxxx-1234"},
        {13, 4, "010-xxxx-7809"},
        {14, 3, "010-xxxx-4785"},
        {15, 2, "010-xxxx-7345"} };
    
    init_queue();
    for (int i = 0; i < (sizeof(waiting) / sizeof(waiting[0])); i++)
    {
        printf("웨이팅 신청을 완료했습니다. 대기번호 %d번 인원 %d명\n", waiting[i].id, waiting[i].nperson);
        enqueue(waiting[i]);
    }

    while (!is_empty())
    {
        Element w = dequeue();
        printf("%d번 입장하실 차례입니다.(%s)\n", w.id, w.info);
    }
    
    return 0;
}
