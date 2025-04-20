typedef struct DNode {
    Element data;
    struct DNode* prev;
    struct DNode* next;
}DNode;

DNode org;

DNode* alloc_dnode(Element e)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->data = e;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

Element free_dnode (DNode* p)
{
    Element e = p->data;
    free(p);
    return e;
}

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

int is_empty(void) { return org.next == NULL; }
int is_full(void) { return 0; }
void init_list(void) { org.next = NULL; }

DNode* get_node(int pos) // 노드 주소 가져옴
{
    DNode* p = &org;
    for (int i = 0; i <= pos; i++, p=p->next)
    {
        if(p == NULL) return NULL;
        return p;
    }
}

Element get_entry (int pos) // 값 가져옴
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL) error("Invalid Position Error!");
    else return p->data;
}

void insert(int pos, Element e)
{
    // p->next, p->prev, before->next, after->prev 값 조정
    DNode* before = get_node(pos - 1);
    if(before == NULL) error("Invalid Position Error!");
    DNode* p = alloc_dnode(e);
    p->next = before->next;
    p->prev = before;
    before->next = p;
    if (p->next != NULL) p->next->prev = p;
}

Element delete (int pos)
{
    // p의 이전 노드->next를 p->next 값으로 / p->next값이 있으면 p->next->prev 를 p의 이전 노드로 / free
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL) error("Invalid Position Error!");
    p->prev->next = p->next;
    if (p->next != NULL) p->next->prev = p->prev;
    return free_dnode(p);
}

void destroy_list(void)
{
    // 리스트 다 삭제, 노드 다 free
    while(!is_empty()) delete(0);
}

int size(void)
{
    int count = 0;
    for (DNode* p = org.next; p!= NULL; p = p->next) count++;
    return count;
}
