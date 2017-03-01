#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY 10
int unsorted_array[SIZEOFARRAY] = {99,8,77,55,6,34,23,12,1,5};
int array_size = SIZEOFARRAY-1;

void print_array(int *arr, int size)
{
    int i = 0;
    for(i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(int *arr, int start, int end)
{
    int i;
    int pivot = arr[end];
    int partitionIndex = start;
    for (i = start; i<end; i++) {
        if(arr[i] < pivot) {
            swap(arr+i,arr+partitionIndex);
            partitionIndex++;
        }
    }
    swap(&(arr[partitionIndex]), arr+end);
    return partitionIndex;
}

void quicksort(int *arr, int start, int end)
{
    int partitionIndex;
    if(start < end) {
        partitionIndex = partition(arr, start, end);
        quicksort(arr, start, partitionIndex-1);
        quicksort(arr, partitionIndex+1, end);
    }
}


int main()
{
    printf("input array is: \n");
    print_array(unsorted_array, array_size);
    printf("Quick sorted array:\n");
    quicksort(unsorted_array, 0, array_size);
    print_array(unsorted_array, array_size);

    return 0;
}


