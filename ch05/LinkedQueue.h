
typedef struct Node {
    Element data;	
    struct Node* link;
} Node;

Node* front = NULL;	
Node* rear = NULL;	

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
};

int is_empty(void)		{ return front == NULL; }
int is_full(void)		{ return 0; }
void init_queue(void)	{ front = rear = NULL; }

int size(void)
{
    int count = 0;
    for (Node* p = front; p != NULL; p = p->link) count++;
    return count;
}

void enqueue(Element e)
{
    Node* p = alloc_node(e);
    if (is_empty())       
        front = rear = p; 
    else {                 
        rear->link = p;    
        rear = p;       
    }
}

Element dequeue(void)
{
    if (is_empty())
        error("Underflow Error!");

    Node* p = front;      
    front = front->link;   
    if (front == NULL)     
        rear = NULL;       
    return free_node(p);  
}

Element peek(void)
{
    if (is_empty())
	error("Underflow Error!");
    return front->data;
}

void destroy_queue(void)
{
    while (is_empty() == 0)
	dequeue();
}
