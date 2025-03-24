#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} Elem;

void print_mat2 (Elem m[], int len, char* str)
{
    printf("%s: ", str);
    for (int i = 0; i < len; i++)
    {
        printf(" (%d,%d,%d)", m[i].row, m[i].col, m[i].value);
    }
    printf("\n");
}

void transpose_mat2 (Elem m[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int tmp = m[i].row;
        m[i].row = m[i].col;
        m[i].col = tmp;
    }
}

int main ()
{
    Elem mat[5] = { {0, 3, 11}, {2, 5 ,42}, {3, 1, 33}, {4, 4, 87}, {5, 4, 55} };
    print_mat2(mat, 5, "희소 행렬");
    transpose_mat2(mat, 5);
    print_mat2(mat, 5, "전치 행렬");

    return 0;
}