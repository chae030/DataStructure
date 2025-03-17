#include <stdio.h>
#include <math.h>

#define MAX_TERMS 80

typedef struct
{
    int expo;
    float coef;
} Term;

typedef struct {
    int nTerms;
    Term term[MAX_TERMS];
} SparsePoly;

float evaluate (SparsePoly a, float x)
{
    float result = 0;
    for (int i = 0; i <a.nTerms; i++)
    {
        result += (float)(a.term[i].coef * pow(x, a.term[i].expo));
    }

    return result;
}

SparsePoly add (SparsePoly a, SparsePoly b)
{
    SparsePoly c;
    c.nTerms = 0;
    for (int i = 0, j = 0; i < a.nTerms || j < b.nTerms;)
    {
        if (i == a.nTerms || a.term[i].expo < b.term[j].expo)
        {
            c.term[c.nTerms++] = b.term[j++];
        }
        else if (j == b.nTerms || a.term[i].expo > b.term[j].expo)
        {
            c.term[c.nTerms++] = a.term[i++];
        }
        else
        {
            c.term[c.nTerms] = a.term[i++];
            c.term[c.nTerms++].coef += b.term[j++].coef;
        }
    }

    return c;
}

void print_spoly (SparsePoly p, char str[])
{
    printf("%s", str);
    for (int i = 0; i <p.nTerms; i++)
    {
        printf("%5.1f", p.term[i].coef);
        if (p.term[i].expo > 0)
        {
            printf(" x^%d ", p.term[i].expo);
            if (i != p.nTerms - 1) printf("+ ");
        }
    }
    printf("\n");
}

int main ()
{   
    SparsePoly a = { 2, {{100, 10.0f}, {0, 6.0f}} };
    SparsePoly b = { 2, {{50, 1.1f}, {3, 2.0f}} };
    SparsePoly c = add(a, b);

    print_spoly(a, " A = ");
    print_spoly(b, " B = ");
    print_spoly(c, " A + B = ");

    printf("A(1)= %f\n", evaluate(a, 1.0f));
    printf("B(2)= %f\n", evaluate(b, 2.0f));

    return 0;
}
