#include <stdio.h>
#include <stdlib.h>

struct Waiting {
    int id;
    int nperson;
    char info[32];
};
typedef struct Waiting Element;
#include "DbLinkedList.h"

void reserve (int nperson, const char info[]) // const 변경 불가
{
    static int id = 0; // static 함수 호출 시에 값 유지 (함수가 게속 호출돼도 이 변수는 처음 한 번만 초기화됨)
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
    
}

void cancel(int wid)
{

}

void delay(int wid)
{

}

void print_waiting(void)
{

}

void service(void)
{

}

int main(void)
{
    init_list();
    print_waiting();

    reserve(2, "010-xxxx-8762"); // 웨이팅 등록 (인원, 전화번호)
    reserve(2, "010-xxxx-3303");
    reserve(5, "010-xxxx-1212");
    reserve(1, "010-xxxx-2305");
    print_waiting();

    service(); // 첫번째 팀 입장
    print_waiting();

    reserve(3, "010-xxxx-4949");
    reserve(4, "010-xxxx-7345");
    print_waiting();

    find(4); // 고객 4가 자신의 순서 확인
    delay(3); 
    delay(3); // 고객의 순서를 2번 뒤로 밀기
    print_waiting();
    cancel(5); // 고객 5번이 대기 취소
    print_waiting();

    destroy_list();

    return 0;
}
