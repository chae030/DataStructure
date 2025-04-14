#include <stdio.h>
#include <stdlib.h>

struct Waiting {
    int id;
    int nperson;
    char info[32];
};
typedef struct Waiting Element;
#include "DbLinkedList.h"

void reserve (int nperson, const char info[])
{
    static int id = 0;
    Element e;
    e.id = ++id;
    e.nperson = nperson;
    strcpy_s(e.info, 32, info);
    insert(size(), e);
    printf("<등록> 번호 %d: 인원 %d명 %s\n", e.id, e.nperson, e.info);
}

void find (int wid)
{
    int nTeam = 0, nPeople = 0;
    // 234p 보고 마저 치기~~
}