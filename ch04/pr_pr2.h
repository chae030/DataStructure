Element data[MAX_SIZE];
int front, rear;

void error (char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_deque (void)
{
    front = rear = 0;
}

int is_empty (void)
{
    return front == rear;
}

int is_full (void)
{
    return front == (rear+1) % MAX_SIZE;
}

void add_front (Element e)
{
    if (is_full()) error("Overflow Error!");
    data[front] = e;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}

Element delete_front (void)
{
    if (is_empty()) error("Underflow Error!");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element get_front (void)
{
    if (is_empty()) error("Underflow Error!");
    return data[(front+1) % MAX_SIZE];
}

void add_rear (Element e)
{
    if(is_full()) error("Overflow Error!");
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = e;
}

Element delete_rear (void)
{
    if(is_empty()) error("Underflow Error!");
    int prev = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[prev];
}

Element get_rear (void)
{
    if(is_empty()) error("Underflow Error!");
    return data[rear];
}
