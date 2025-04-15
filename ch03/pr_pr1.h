typedef struct {
    Element data[MAX_SIZE];
    int top;
}Stack;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_stack(Stack* s)
{
    s->top = -1;
}

int is_empty(Stack* s)
{
    if (s->top == -1) return 1;
    else return 0;
}

int is_full(Stack* s)
{
    return (s->top == (MAX_SIZE - 1));
}

void push(Stack* s, Element e)
{
    if (is_full(s))
        error("Overflow Error!");
    else s->data[++(s->top)] = e;
}

Element pop(Stack* s)
{
    if (is_empty(s))
        error("Underflow Error!");
    return s->data[(s->top)--];
}

Element peek(Stack* s)
{
    if(is_empty(s))
        error("Underflow Error!");
    return s->data[s->top];
}
