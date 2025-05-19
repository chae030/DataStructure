#include <stdio.h>
typedef struct {
    int x, y;
} Point2D;
#define Element Point2D

int x_ascend(Element a, Element b) { return (b.x - a.x); }
int y_descend(Element a, Element b) { return (a.y - b.y); }
int z_ascend(Element a, Element b) {
    return ((b.x * b.x + b.y * b.y) - (a.x * a.x + a.y * a.y));
}

void insertion_sort_fn(Element A[], int n, int(*f)(Element, Element))
{
    for (int i = 1; i < n; i++) {
        Element key = A[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (f(A[j], key) < 0) A[j + 1] = A[j];
            else break;
        }
        A[j+1] = key;
    }
}

void print_point_array(Element arr[], int n, char str[])
{
    printf("%s", str);
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}

int main(void)
{
    Element list[9] = { {6,6}, {7,4}, {2,3}, {1,5}, {5,2}, {3,3}, {9,4}, {1,8}, {5,3} };
    print_point_array(list, 9, "Original : ");
    insertion_sort_fn(list, 9, x_ascend);
    print_point_array(list, 9, "x_ascend : ");
    insertion_sort_fn(list, 9, y_descend);
    print_point_array(list, 9, "y_descend: ");

    insertion_sort_fn(list, 9, z_ascend);
    print_point_array(list, 9, "z_ascend : ");

    return 0;
}
