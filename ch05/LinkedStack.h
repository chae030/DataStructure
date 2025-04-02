typedef struct Node {   
    Element data;    
    struct Node* link; 
} Node;
Node* top = NULL;

Node* alloc_node(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e; 
    p->link = NULL; 
    return p;
}
Element free_node(Node* p)
{
    Element e = p->data;    
    free(p);           
    return e;           
}

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

int is_empty() { return top == NULL; }
int is_full() { return 0; }
void init_stack() { top = NULL; }

void push(Element e)
{
    Node* p = alloc_node(e);
    p->link = top;          
    top = p;               
}

Element pop(void)
{
    if (is_empty())
        error("Underflow Error!");
    Node* p = top;          
    top = p->link;         
    return free_node(p);    
}

Element peek(void)
{
    if (is_empty())
        error("Underflow Error!");
    return top->data;
}

void destroy_stack(void)
{
    while (is_empty() == 0) pop();
}

int size(void)
{
    int count = 0;
    for (Node* p = top; p != NULL; p = p->link)
        count++;
    return count;
}
