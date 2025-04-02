#include <stdio.h>
#include <stdlib.h>

typedef int Element;
Element *data;
int front, rear, MAX_SIZE;

void error(char *str)
{
    printf("%s\n", str);
    exit(1);
}

void init_queue(void)
{
    front = rear = 0;
    MAX_SIZE = 2;
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
}

int is_empty(void)
{
    return front == rear;
}

int is_full (void)
{
    return front == (rear+1) % MAX_SIZE;
}

void enqueue (Element e)
{
    if (is_full())
    {
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE * 2);
        if (rear > front)
        {
            for (int i = 0; i <= rear; i++)
            {
                data[MAX_SIZE + i] = data[i];
            }
            rear += MAX_SIZE;
        }
        MAX_SIZE *= 2;
        printf("\n큐 확장(큐 크기:%d)\n", MAX_SIZE);
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = e;
}

Element dequeue(void)
{
    if (is_empty()) error("Underflow Error!");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek(void)
{
    if (is_empty()) error("Underflow Error!");
    return data[(front+1) % MAX_SIZE];
}

int main(void) 
{
    init_queue();
    for (int i = 0; i < 5; i++) enqueue(i);
    for (int i = 0; i < 2; i++) dequeue();
    for (int i = 0; i < 5; i++) enqueue(i);
    for (int i = 0; i < 10; i++) printf(" %d ", dequeue());
    printf("\n");

    return 0;
}
