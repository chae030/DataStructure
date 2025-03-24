#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_mat(int mat[ROWS][COLS], const char *msg) {
    printf("%s:\n", msg);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_mat(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void mul_mat(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            c[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matA[ROWS][COLS] = {{4, 0, 1}, {1, 6, 5}, {7, 3, 6}};
    int matB[ROWS][COLS] = {{4, 0, 1}, {1, 6, 5}, {7, 3, 6}};
    int matC[ROWS][COLS];
    
    print_mat(matA, "원래 행렬A");
    print_mat(matB, "원래 행렬B");
    
    add_mat(matA, matB, matC);
    print_mat(matC, "행렬 덧셈");
    
    mul_mat(matA, matB, matC);
    print_mat(matC, "행렬 곱셈");

    return 0;
}
