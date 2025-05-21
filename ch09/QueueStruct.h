// 쉽게 배우는 C자료구조(최영규, 생능 출판사, 2024)
// 참고파일 ch04/QueueStruct.h


//-------------------------------------------------------------
// 코드 4.5 구조체와 매개변수 전달을 이용한 원형 큐


// QueueStruct.h: 큐 추상 자료형의 구현(원형큐)
// 원형 큐의 데이터를 구조체에 모음
// 저장할 데이터의 자료형 Element를 먼저 정의해야 함.
typedef struct Queue {
    Element data[MAX_SIZE]; // 요소의 배열
    int front;              // 전단 인덱스
    int rear;               // 후단 인덱스
} Queue;
void error(char* str)
{
    printf("%s\n", str);
    exit(1);
};
void init_queue(Queue* q)
{
    q->front = q->rear = 0;
}
int is_empty(Queue* q)
{
    return q->front == q->rear;
}
int is_full(Queue* q)
{
    return q->front == (q->rear + 1) % MAX_SIZE;
}
void enqueue(Queue* q, Element val)
{
    if (is_full(q))
        error("Overflow Error!");
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = val;
}
Element dequeue(Queue* q)
{
    if (is_empty(q))
        error("Underflow Error!");
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}
Element peek(Queue* q)
{
    if (is_empty(q))
        error("Underflow Error!");
    return q->data[(q->front + 1) % MAX_SIZE];
}

// 요소의 수 계산
int size(Queue* q)
{
    return(q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}
