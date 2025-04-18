Element data[MAX_SIZE];
int size = 0;

void error (char str[])
{
    printf("%s", str);
    exit(1);
}

void init_list(void) { size = 0; }
int is_empty(void) { return size == 0; }
int is_full(void) { return size == MAX_SIZE; }

void insert(int pos, Element e)
{
    if (is_full())
    {
        error("Overflow Error!");
    }

    if (pos < 0 || pos > size)
    {
        error("Invalid Position Error!");
    }

    for (int i = size - 1; i >= pos; i--) // 맨 뒤의 요소부터 한칸씩 뒤로 이동  
    {
        data[i+1] = data[i];
    }
    data[pos] = e;
    size += 1;
}

Element delete(int pos)
{
    if(is_empty())
    {
        error("Underflow Error!");
    }

    if (pos < 0 || pos >= size)
    {
        error("Invalid Position Error!");
    }

    Element e = data[pos];
    for(int i = pos + 1; i < size; i++) // pos+1 부터 한칸씩 앞으로 이동
    {
        data[i-1] = data[i];
    }
    size -= 1;
    return e;
}

Element get_entry(int pos)
{
    if(is_empty())
    {
        error("Underflow Error!~");
    }

    if(pos <0 || pos >= size)
    {
        error("Invalid Position Error!");
    }

    return data[pos];
}

void append(Element e)
{
    insert(size, e);
}

Element pop(void)
{
    return delete(size-1);
}

void replace (int pos, Element e)
{
    if (pos < 0 || pos > size)
    {
        error("Invalid Position Error!");
    }

    data[pos] = e;
}

int find (Element e)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == e) return i;
    }
    return -1;
}
