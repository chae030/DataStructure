// 원형 큐의 데이터 (Element 와 MAX_SIZE) 는 미리 정의되어 있어야 함
Element data[MAX_SIZE];
int front;
int rear;

void error (char *str) 
{
    printf("%s\n", str);
    exit(1);
}

// 원형 큐의 주요 연산들
void init_queue(void)
{
    front = rear = 0;
}
int is_empty(void)
{
    return front == rear;
}
int is_full(void)
{
    return front == (rear + 1) % MAX_SIZE;
}

void enqueue(Element e)
{
    if (is_full())
        error("Overflow Error!");
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = e;
}

// 원형큐의 삭제 연산
Element dequeue(void)
{
    if (is_empty())
        error("Underflow Error!");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

// 원형큐의 탐색(peek) 연산
Element peek(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[(front + 1) % MAX_SIZE];
}
