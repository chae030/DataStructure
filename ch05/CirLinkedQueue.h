// 큐의 데이터 (Element는 미리 정의되어 있어야 함. MAX_SIZE는 필요 없음.)
typedef struct Node { 
    Element data; 
    struct Node* link; 
} Node;

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
}

int is_empty(void) { return rear == NULL; }
int is_full(void) { return 0; }
void init_queue(void) { rear = NULL; }

// 삽입 연산
void enqueue(Element e)
{
    Node* p = alloc_node(e); 
    if (is_empty()) { 
        rear = p;
        p->link = p;
    }
    else { 
        p->link = rear->link;
        rear->link = p;
        rear = p; 
    }
}

// 삭제 연산
Element dequeue(void)
{
    if (is_empty())
        error("Underflow Error!");
    Node* p = rear->link;
    if (rear == p) 
        rear = NULL;
    else 
        rear->link = p->link; 
    return free_node(p);
}

// 탐색 연산
Element peek(void)
{
    if (is_empty())
        error("Underflow Error!");
    return rear->link->data; 
}

// 모든 요소 삭제 (동적 해제) 연산
void destroy_queue(void)
{
    while (is_empty() == 0) dequeue();
}

int size(void)
{
    if (is_empty()) 
        return 0;
    int count = 1;
    for (Node* p = rear->link; p != rear; p = p->link)
        count++;
    return count;
}
