#include <stdio.h>
#define SWAP(x,y,t)	((t)=(x),(x)=(y),(y)=(t))

// 9.1
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void print_step(int arr[], int n, int val)
{
    printf("   Step%2d :", val);
    print_array(arr, n);
}

void selection_sort(int A[], int n)
{
    int tmp;
    for (int i = 0; i < n-1; i++) {
        int least = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[least]) least = j;
        }
        SWAP(A[i], A[least], tmp);
        print_step(A, n, i+1);
    }
}

// 9.2
void insertion_sort(int A[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j;
        for (j = i-1; j >= 0; j--) {
            if(A[j] > key) A[j+1] = A[j];
            else break;
        }
        A[j+1] = key;
        print_step(A, n, i);
    }
}

// 9.3
void bubble_sort(int A[], int n)
{
    int tmp;
    for (int end = n-1; end > 0; end--) {
        int bChanged = 0;
        for (int j = 0; j < end; j++) {
            if (A[j] > A[j+1]) {
                SWAP(A[j], A[j+1], tmp);
                bChanged = 1;
            }
        }
        if(!bChanged) break;
        print_step(A, n, n-end);
    }
}

// 9.4
int ascend(int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }
void insertion_sort_fn(int A[], int n, int(*f)(int, int))
{
    for (int i = 1; i < n; i++) {
        int key = A[i];					
        int j;
        for (j = i - 1; j >= 0; j--) {	
            if (f(A[j], key) < 0) A[j + 1] = A[j];		
            else break;		          
        }
        A[j + 1] = key;			
        print_step(A, n, i);		
    }
}

