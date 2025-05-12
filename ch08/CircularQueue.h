// 쉽게 배우는 C자료구조(최영규, 생능 출판사, 2024)
// 참고파일 ch04/CircularQueue.h


//-------------------------------------------------------------
// 코드 4.1 배열을 이용한 원형 큐의 구현

// 원형 큐의 데이터(Element와 MAX_SIZE는 미리 정의되어 있어야 함)
Element data[MAX_SIZE]; // 요소의 배열
int front; // 전단 인덱스
int rear; // 후단 인덱스
void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}
// 원형 큐의 주요 연산들
void init_queue()
{
    front = rear = 0;
}
int is_empty()
{
    return front == rear;
}
int is_full()
{
    return front == (rear + 1) % MAX_SIZE;
}
void enqueue(Element val)
{
    if (is_full())
        error("Overflow Error!");
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = val;
}
// 원형큐의 삭제 연산
Element dequeue()
{
    if (is_empty())
        error("Underflow Error!");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}
// 원형큐의 탐색(peek) 연산
Element peek()
{
    if (is_empty())
        error("Underflow Error!");
    return data[(front + 1) % MAX_SIZE];
}
