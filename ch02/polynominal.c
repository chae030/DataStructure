#include <stdio.h>

#define MAX_DEGREE 1001

typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
} Polynominal;

int degree (Polynominal p)
{
    return p.degree;
}

float coefficient (Polynominal p, int i)
{
    return p.coef[i];
}

float evaluate (Polynominal p, float x)
{
    float result = p.coef[0];
    float mul = 1;
    for (int i = 1; i <= p.degree; i++) 
    {
        mul *= x;
        result += p.coef[i] * mul;
    }

    return result;
}

Polynominal add (Polynominal a, Polynominal b)
{
    Polynominal p;
    p.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (int i = 0; i < p.degree; i++)
    {
        p.coef[i] = ((i <= a.degree) ? a.coef[i] : 0) + ((i <= b.degree) ? b.coef[i] : 0);
    }

    return p;
}

void print_poly (Polynominal p, char str[])
{
    printf(" %s", str);
    for (int i = p.degree; i > 0; i--)
    {
        printf("%5.1f x^%d + ", p.coef[i], i);
    }
    printf("%4.1f\n", p.coef[0]);
}

int main ()
{
    Polynominal a = { 5, { 3, 6, 0, 0, 0, 10} };
    Polynominal b = { 4, { 7, 0, 5, 0, 1} };
    Polynominal c = add(a,b);

    print_poly(a, " A = ");
    print_poly(b, " B = ");
    print_poly(c, " A + B = ");

    printf("A(1) = %f\n", evaluate(a, 1.0f));
    printf("B(2) = %f\n", evaluate(b, 2.0f));

    return 0;
}