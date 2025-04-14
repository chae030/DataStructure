typedef struct DNode {
    Element data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode org;

DNode* alloc_dnode (Element e)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p -> data = e;
    p -> prev = NULL;
    p -> next = NULL;
    return p;
}

Element free_dnode(DNode* p)
{
    Element e = p -> data;
    free(p);
    return e;
}

void error (char* str)
{
    printf("%s\n", str);
    exit(1);
}

int is_empty(void) { return org.next == NULL; }
int is_full(void) { return 0; }
void init_list(void) { org.next = NULL; }

DNode* get_node(int pos)
{
    DNode* p = &org;
    for (int i = 0; i <= pos; i ++, p = p -> next)
    {
        if (p == NULL)
        {
            return NULL;
        }
    }
    return p;
}

Element get_entry (int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
    {
        error("Invalid Position Error!");
    }
    return p -> data;
}

void insert (int pos, Element e)
{
    DNode* before = get_node(pos - 1);
    if (before == NULL)
    {
        error("Invalid Position Error!");
    }

    DNode* p = alloc_dnode(e);
    p -> next = before -> next;
    p -> prev = before;
    before -> next = p;
    if (p -> next != NULL)
    {
        p -> next -> prev = p;
    }
}

Element delete (int pos)
{
    DNode * p = get_node(pos);
    if (pos < 0 || p == NULL)
    {
        error("Invalid Position Error!");
    }

    p -> prev -> next = p -> next;
    if (p -> next != NULL)
    {
        p -> next -> prev = p -> prev;
    }

    return free_dnode(p);
}

void destroy_list(void) { while (is_empty() == 0) delete(0); }

int size(void)
{
    int count = 0;
    for (DNode* p = org.next; p != NULL; p = p -> next)
    {
        count++;
    }
    return count;
}
