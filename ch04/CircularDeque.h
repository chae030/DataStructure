#include "CircularQueue.h"

void init_deque(void)
{
    init_queue();
}
void add_rear(Element val)
{
    enqueue(val);
}
Element delete_front(void)
{
    return dequeue();
}
Element get_front(void)
{
    return peek();
}

void add_front(Element val)
{
    if(is_full())
    {
        error("Overflow Error!");
    }
    data[front] = val;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_rear(void)
{
    if (is_empty())
    {
        error("Underflow Error!");
    }
    int prev = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[prev];
}
Element get_rear(void)
{
    if (is_empty())
    {
        error("Underflow Error!");
    }
    return data[rear];
}
