/*
 * Sorting Algos
 *
 * Author: Anand Kumar Neeli
 * Date  : March 2017
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY 10
int unsorted_array[SIZEOFARRAY] = {99,8,77,55,6,34,23,12,1,5};
int scramble_array[SIZEOFARRAY] = {99,8,77,55,6,34,23,12,1,5};
int array_size = SIZEOFARRAY-1;

void print_array(int *arr, int size)
{
    int i = 0;
    for(i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void scramble(int *arr)
{
    int i;
    for (i = 0; i <= array_size; i++) {
        arr[i] = scramble_array[i];
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
input array is: 
99 8 77 55 6 34 23 12 1 5 
Bubble sorted array:
8 77 55 6 34 23 12 1 5 99 
8 55 6 34 23 12 1 5 77 99 
8 6 34 23 12 1 5 55 77 99 
6 8 23 12 1 5 34 55 77 99 
6 8 12 1 5 23 34 55 77 99 
6 8 1 5 12 23 34 55 77 99 
6 1 5 8 12 23 34 55 77 99 
1 5 6 8 12 23 34 55 77 99 
1 5 6 8 12 23 34 55 77 99 

*/
void bubblesort(int *arr, int size)
{
    int i,j, swap_flag = 0;

    for(i = 0; i <=size; i++) {
        swap_flag = 0;
        for(j = 0; j <= size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr+j,arr+j+1);
                swap_flag = 1;
            }
            //printf("i=%d j=%d\n",i,j);
        }
        if (!swap_flag) break;
        //print_array(arr, size);
    }
}

/*
input array:
99 8 77 55 6 34 23 12 1 5 
Selection sorted array:
~1 8 77 55 6 34 23 12 ~99 5 
1 ~5 77 55 6 34 23 12 99 ~8 
1 5 ~6 55 ~77 34 23 12 99 8 
1 5 6 ~8 77 34 23 12 99 ~55 
1 5 6 8 ~12 34 23 ~77 99 55 
1 5 6 8 12 ~23 ~34 77 99 55 
1 5 6 8 12 23 34 77 99 55 
1 5 6 8 12 23 34 55 99 77 
1 5 6 8 12 23 34 55 77 99 
1 5 6 8 12 23 34 55 77 99 
1 5 6 8 12 23 34 55 77 99 
*/
void selectionsort(int *arr, int size)
{
    int i,j, min_idx;

    for(i = 0; i <=size; i++) {
        min_idx = i;
        for(j = i+1; j <= size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr+i,arr+min_idx);
        //print_array(arr, size);
        //printf("i=%d j=%d\n",i,j);
    }
}

/*
Scrambling array:
99 8 77 55 6 34 23 12 1 5 
Insertion sorted array:
~8 ~99 77 55 6 34 23 12 1 5 
8 ~77 ~99 55 6 34 23 12 1 5 
8 ~55 ~77 ~99 6 34 23 12 1 5 
6 ~8 ~55 ~77 ~99 34 23 12 1 5 
6 8 ~34 ~55 ~77 ~99 23 12 1 5 
6 8 ~23 ~34 ~55 ~77 ~99 12 1 5 
6 8 ~12 ~23 ~34 ~55 ~77 ~99 1 5 
~1 ~6 ~8 ~12 ~23 ~34 ~55 ~77 ~99 5 
1 ~5 ~6 ~8 ~12 ~23 ~34 ~55 ~77 ~99 
1 5 6 8 12 23 34 55 77 99 
*/
void insertionsort(int *arr, int size)
{
        int i,j, value, hole;
        for(i = 1; i <= size ; i++) {
            value = arr[i];
            hole = i;
            while ((hole > 0) && (arr[hole-1] > value)) {
                arr[hole] = arr[hole-1];
                hole = hole - 1;
            }
            arr[hole] = value;
            //print_array(arr, size);
        }
}
/* Function to sort an array using insertion sort*/
void insertionSort(int *arr, int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main()
{
    printf("input array is: \n");
    print_array(unsorted_array, array_size);

    printf("Bubble sorted array:\n");
    bubblesort(unsorted_array, array_size);
    print_array(unsorted_array, array_size);

    printf("Scrambling array:\n");
    scramble(unsorted_array);
    print_array(unsorted_array, array_size);

    printf("Selection sorted array:\n");
    selectionsort(unsorted_array, array_size);
    print_array(unsorted_array, array_size);

    printf("Scrambling array:\n");
    scramble(unsorted_array);
    print_array(unsorted_array, array_size);

    printf("Insertion sorted array:\n");
    insertionsort(unsorted_array, array_size);
    print_array(unsorted_array, array_size);

    return 0;
}
