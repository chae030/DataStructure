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


// 9.6
#define MAX_SIZE 1024

void merge(int A[], int left, int mid, int right)
{
    static int sorted[MAX_SIZE];
    int i = left;
    int j = mid+1;
    int k = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            sorted[k++] = A[i++];
        }
        else {
            sorted[k++] = A[j++];
        }
    }
    while (i <= mid  ) sorted[k++] = A[i++];
    while (j <= right) sorted[k++] = A[j++];

    for (i = left; i <= right; i++) {
        A[i] = sorted[i];
    }
}

void merge_sort(int A[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void printArray(int arr[], int n, char* str)
{
    printf("%s =", str);
    print_array(arr, n);
}

// int main(void)
// {
//     int list[] = {6, 3, 7, 4, 9, 1, 5};
//     printArray(list, 7, "Original ");
//     merge_sort(list, 0, 6);
//     printArray(list, 7, "MergeSort");

//     return 0;
// }

// 9.7
int partition(int A[], int left, int right)
{
    int pivot = A[left];
    int low = left + 1;
    int high = right;
    int tmp;

    while (low <= high) {
        while (low <= high && A[low] <= pivot) low++;
        while (low <= high && A[high] > pivot) high--;
        if (low < high) {
            SWAP(A[low], A[high], tmp);
        }
    }
    SWAP(A[left], A[high], tmp);
    return high;
}

void quick_sort(int A[], int left, int right)
{
    if (left < right) {
        int q = partition(A, left, right);
        quick_sort(A, left, q-1);
        quick_sort(A, q+1, right);
    }
}

int compare(void *arg1, void *arg2)
{
    if(*(double *)arg1 > *(double *)arg2) return 1;
    else if (*(double *)arg1 < *(double *)arg2) return -1;
    else return 0;
}

int main(void)
{
    double list[9] = {2.1, 0.9, 1.6, 3.8, 1.2, 4.4, 6.2, 9.1, 7.7};

    printf("정렬 전: ");
    for (int i = 0; i < 9; i++) {
        printf("%4.1f ", list[i]);
    }

    qsort((void *)list, 9, sizeof(double), compare);
    printf("\n정렬 후: ");
    for (int i = 0; i < 9; i++) {
        printf("%4.1f ", list[i]);
    }
    printf("\n");

    return 0;
}
