Element data[MAX_SIZE];
int front, rear, size;

void error (char str[])
{
    printf("%s", str);
    exit(1);
}

void init_queue(void)
{
    front = 0;
    rear = 0;
    size = 0;
}

int is_empty(void)
{
    return size == 0;
}

int is_full(void)
{
    return size == MAX_SIZE;
}

int is_size (void)
{
    return size;
}

void enqueue (Element e)
{
    if (is_full()) error("Overflow Error!");
    rear = (rear+1) % MAX_SIZE;
    data[rear] = e;
    size ++;
}

Element dequeue (void)
{
    if (is_empty()) error("Underflow Error!");
    front = (front+1) % MAX_SIZE;
    size--;
    return data[front];
}

Element peek (void)
{
    if(is_empty()) error("Underflow Error!");
    return data[(front+1) % MAX_SIZE];
}