
Element data[MAX_SIZE];
int top;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_stack(void)
{
    top = -1;
}

int is_empty(void)
{
    if (top == -1) return 1;
    else return 0;
}

int is_full(void)
{
    return (top==(MAX_SIZE - 1));
}

void push(Element e)
{
    if (is_full())
        error("Overflow Error!");
    else data[++top] = e;
}

Element pop(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[top--];
}

Element peek(void)
{
    if(is_empty())
        error("Underflow Error!");
    return data[top];
}
