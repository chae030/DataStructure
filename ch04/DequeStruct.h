#include "QueueStruct.h"

typedef Queue Deque;

void init_deque(Deque *deque)
{
    init_queue(deque);
}
void add_rear(Deque *deque, Element val)
{
    enqueue(deque, val);
}
Element delete_front(Deque *deque)
{
    return dequeue(deque);
}
Element get_front(Deque *deque)
{
    return peek(deque);
}

void add_front(Deque *deque, Element val)
{
    if (is_full(deque))
    {
        error("Overflow Error!");
    }
    deque->data[deque->front] = val;
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_rear(Deque *deque)
{
    if (is_empty(deque))
    {
        error("Underflow Error!");
    }
    int prev = deque->rear;
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return deque->data[prev];
}
Element get_rear(Deque *deque)
{
    if (is_empty(deque))
    {
        error("Underflow Error!");
    }
    return deque->data[deque->rear];
}
