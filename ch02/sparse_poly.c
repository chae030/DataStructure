#include <stdio.h>
#include <math.h>
#define MAX_TERMS 80

typedef struct // 하나의 항
{
    int expo; // 항의 지수
    float coef; // 항의 계수
} Term;

typedef struct { // 희소 다항식 (계수가 0이 아닌 항들만)
    int nTerms; // 계수가 0이 아닌 항의 개수
    Term term[MAX_TERMS]; // 계수가 0이 아닌 항의 배열
} SparsePoly;

float evaluate (SparsePoly a, float x) // 미지수 x에 값을 대입했을 때 결과를 반환하는 함수
{
    float result = 0;
    for (int i = 0; i <a.nTerms; i++)
    {
        result += (float)(a.term[i].coef * pow(x, a.term[i].expo));
        // result에 항의 값 (계수 * x의 지수승)을 누적 덧셈 (pow는 거듭제곱을 계산하는 함수 pow(2,3)은 2의 3승)
    }

    return result;
}

SparsePoly add (SparsePoly a, SparsePoly b) // 두 희소 다항식을 더하는 함수
{
    SparsePoly c;
    c.nTerms = 0; // c의 항 개수 초기화
    for (int i = 0, j = 0; i < a.nTerms || j < b.nTerms;) // a 나 b 둘 중 하나라도 남아있을 때 반복
    {
        if (i == a.nTerms || a.term[i].expo < b.term[j].expo) // a의 항 개수가 0이거나 a의 차수 < b의 차수
        {
            c.term[c.nTerms++] = b.term[j++]; // b의 항을 c에 추가
        }
        else if (j == b.nTerms || a.term[i].expo > b.term[j].expo) // b의 항이 더이상 없거나 a의 지수가 더 크면
        {
            c.term[c.nTerms++] = a.term[i++]; // a의 항을 c에 추가
        }
        else // a와 b 지수가 같은 경우 (차수가 같은 경우) 계수끼리 더해서 하나의 항으로 만듦
        {
            c.term[c.nTerms] = a.term[i++];
            c.term[c.nTerms++].coef += b.term[j++].coef;
        }
    }

    return c;
}

void print_spoly (SparsePoly p, char str[]) // 다항식을 출력하는 함수
{
    printf("%s", str);
    for (int i = 0; i <p.nTerms; i++)
    {
        printf("%5.1f", p.term[i].coef); // 계수 출력
        if (p.term[i].expo > 0) // 지수가 0보다 크면
        {
            printf(" x^%d ", p.term[i].expo); // x^지수 형식 출력
            if (i != p.nTerms - 1) printf("+ "); // 마지막 항이 아니면 + 출력
        }
    }
    printf("\n");
}

int main (void)
{   
    SparsePoly a = { 2, {{100, 10.0f}, {0, 6.0f}} }; // 항 2개, {x의 100승, 계수 10}, {상수항, 계수 6} 즉 10.0x^100 + 6.0
    SparsePoly b = { 2, {{50, 1.1f}, {3, 2.0f}} }; // 1.1x^50 + 2.0x^3
    SparsePoly c = add(a, b);

    print_spoly(a, " A = ");
    print_spoly(b, " B = ");
    print_spoly(c, " A + B = ");

    printf(" A(1) = %f\n", evaluate(a, 1.0f));
    printf(" B(2) = %f\n", evaluate(b, 2.0f));

    return 0;
}
