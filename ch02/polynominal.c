#include <stdio.h>
#define MAX_DEGREE 1001

typedef struct
{
    int degree; //다항식의 차수
    float coef[MAX_DEGREE]; // 계수의 배열 (지수가 0일 때부터 입력)
} Polynominal;

int degree (Polynominal p) // 다항식 p의 차수 반환
{
    return p.degree;
}

float coefficient (Polynominal p, int i) // p의 지수가 i인 항의 계수 반환 -> x^i항의 계수 반환
{
    return p.coef[i];
}

float evaluate (Polynominal p, float x) //
{
    float result = p.coef[0]; // result에 상수항부터 더함
    float mul = 1; // 초깃값 (x^i 표기 위함)
    for (int i = 1; i <= p.degree; i++) 
    {
        mul *= x; // 계속 곱해주면서 x^i 포현
        result += p.coef[i] * mul; // x^i * 계수 를 result에 추가로 더함
    }

    return result;
}

Polynominal add (Polynominal a, Polynominal b)
{
    Polynominal p;
    p.degree = (a.degree > b.degree) ? a.degree : b.degree; // a와 b 중 차수가 큰 쪽이 결과 다항식의 차수

    for (int i = 0; i < p.degree; i++)
    {
        p.coef[i] = ((i <= a.degree) ? a.coef[i] : 0) + ((i <= b.degree) ? b.coef[i] : 0); // p의 현재 차수가 a의 차수 이하이면 a의 차수를, 아니면 0을 더함
    }

    return p; // 결과 구조체 p (차수, 계수 배열 형태) 반환
}

void print_poly (Polynominal p, char str[])
{
    printf("%s", str);
    for (int i = p.degree; i > 0; i--)
    {
        printf("%5.1f x^%d + ", p.coef[i], i); // 계수x^차수+ 출력 (i = 1 까지)
    }
    printf("%4.1f\n", p.coef[0]); // 계수 배열의 0번째 (= 차수가 0인 부분 = 상수항) 출력
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