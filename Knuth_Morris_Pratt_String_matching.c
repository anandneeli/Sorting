/*
 *Knuth-Morris-Pratt string matching*
 *
 * Author: Anand Kumar Neeli
 * Date  : March 2017
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define PATTERN_SIZE 7
#define ARR_SIZE 13
char arr[ARR_SIZE] = "AAACACAGTTAPP";
char pattern[PATTERN_SIZE] = "ACACAGT";
int prefix[PATTERN_SIZE] = {};


void print_array(char *arr, int size)
{
    int i = 0;
    for(i = 0; i <= size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void print_int_array(int *arr, int size)
{
    int i = 0;
    for(i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void kmp_prefix (char *pat, int pat_size, int *prx)
{
    int i = 0, j = 0;
    prx[i] = 0;
    i = 1;

    while (i < pat_size) {
        if(pat[i] == pat[j]) {
            prx[i] = prx[i-1] + 1;
            i++;
            j++;
        } else {
            prx[i] = 0;
            i++;
            j=0;
        }
    }

}

int kmp_match(char *arr, int arr_size, char *pat, int pat_size, int *prx)
{
    int i = 0, j = 0, index = -1;

    while(i < arr_size) {
        while(j < pat_size) {
           //printf("i: %c j: %c\n", arr[i], pat[j]);
           if (arr[i] != pat[j]) {
                if(prx[j]) {
                    i = i + prx[j];
                }
                j = 0;
            } else {
                i++; j++;
            }
            if (j == pat_size)
                return i - pat_size;
        }
    }

    return index;
}

int main()
{
     int index = 0;
     print_array(arr, ARR_SIZE-1);
     print_array(pattern, PATTERN_SIZE-1);

     kmp_prefix(pattern, PATTERN_SIZE-1, prefix);
     print_int_array(prefix,PATTERN_SIZE-1);

     index = kmp_match(arr, ARR_SIZE-1, pattern, PATTERN_SIZE-1, prefix);
     printf("Index: %d\n", index);


    return 0;
}
