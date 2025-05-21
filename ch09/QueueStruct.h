// ���� ���� C�ڷᱸ��(�ֿ���, ���� ���ǻ�, 2024)
// �������� ch04/QueueStruct.h


//-------------------------------------------------------------
// �ڵ� 4.5 ����ü�� �Ű����� ������ �̿��� ���� ť


// QueueStruct.h: ť �߻� �ڷ����� ����(����ť)
// ���� ť�� �����͸� ����ü�� ����
// ������ �������� �ڷ��� Element�� ���� �����ؾ� ��.
typedef struct Queue {
    Element data[MAX_SIZE]; // ����� �迭
    int front;              // ���� �ε���
    int rear;               // �Ĵ� �ε���
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

// ����� �� ���
int size(Queue* q)
{
    return(q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}
