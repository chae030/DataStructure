#include <stdlib.h>
#include <stdio.h>

#define ROWS 3
#define COLS 3

void print_mat (int mat[ROWS][COLS], char* m)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", mat[i][j]);
        }
    }
    printf("\n");
}

void add_mat(int m1[ROWS][COLS], int m2[ROWS][COLS], int m3[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void mul_mat(int m1[ROWS][COLS], int m2[ROWS][COLS], int m3[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            for (int k = 0; k < ROWS; k++)
            {
                m3[i][j] += m1[k][j] * m2[j][k];
            }
        }
    }
}

int main (void)
{
    int matA[ROWS][COLS] = { 4, 0, 1, 1, 6, 5, 7, 3, 6 };
    int matB[ROWS][COLS] = { 4, 0, 1, 1, 6, 5, 7, 3, 6 };
    int matC[ROWS][COLS];
    print_mat(matA, "원래 행렬 A");
    print_mat(matB, "원래 행렬 B");
    add_mat(matA, matB, matC);
    print_mat(matC, "행렬 덧셈");
    mul_mat(matA, matB, matC);
    print_mat(matC, "행렬 곱셈");

    return 0;
}
