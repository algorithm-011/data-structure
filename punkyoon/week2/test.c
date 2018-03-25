#include <stdio.h>
#include <stdlib.h>

int *heap = NULL;
int n = 0;

void push(int data);
int pop(void);
void upheap(int idx);
void downheap();
void sort(int arr[], int size);

void push(int data)
{
    heap[n] = data;
    upheap(n++);
}

int pop(void)
{
    int temp = heap[0];
    heap[0] = heap[--n];
    downheap();

    return temp;
}

void upheap(int idx)
{
    int val = heap[idx];
    while(idx > 0 && heap[((idx+1)/2)-1] < val)
    {
        heap[idx] = heap[((idx+1)/2)-1];
        idx = ((idx+1)/2) - 1;
    }
    heap[idx] = val;
}

void downheap(void)
{
    int val = heap[0];
    int i = 0;
    while(i <= n/2)
    {
        int j = ((i+1)*2) - 1;
        if(j+1 <= n && heap[j] < heap[j+1])
            j++;
        if(val >= heap[j])
            break;
        heap[i] = heap[j];
        i = j;
    }

    heap[i] = val;
}

void sort(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i] = pop();
        printf("%d: %d\n", i+1, arr[i]);
    }
}

int main(void)
{
    int arr[] = {15, 2, 8, 11, 9, 7};
    int i, size = sizeof(arr) / sizeof(int);

    heap = malloc(sizeof(int) * size + 1);

    for(i=0; i<size; i++)
        push(arr[i]);

    // heap arr
    printf("===== HEAP\n");
    for(i=0; i<size; i++)
        printf("%d ", heap[i]);
    printf("\n");

    sort(arr, size);    // heap sort

    // sorted arr
    printf("===== RESULT\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(heap);
    return 0;
}
