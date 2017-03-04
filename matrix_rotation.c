/*
 * Rotate an nxn matrix clockwise
 *
 * Author: Anand Kumar Neeli
 * Date  : March 2017
 *
 */
/*
 * example
 * Input matrix:
 *     1 2 3
 *     4 5 6
 *     7 8 9
 * 
 * Output matrix:
 *     7 4 1
 *     8 5 2
 *     9 6 3
 * 
 */
/* Explanation at https://www.youtube.com/watch?v=Jtu6dJ0Cb94&t=1797s */


#include <stdio.h>
#include <stdlib.h>


#define SIZE 5
int size = SIZE;
int matrix_nxn[SIZE][SIZE];

void print_matrix(int order, int matrix[order][order])
{
    int x, y;

    for(x = 0; x < order; x++) {
        for(y = 0; y < order; y++) {
            printf("%d", matrix[x][y]);
            if (matrix[x][y] < 10)
                printf("    ");
            else if (matrix[x][y] < 100)
                printf("   ");
            else if (matrix[x][y] < 1000)
                printf("  ");
        }
        printf("\n");
    }
}

void make_matrix(int order, int matrix[order][order])
{
    int x, y, count = 0;

    for(x = 0; x < order; x++) {
        for(y = 0; y < order; y++) 
            matrix[x][y] = count++;
    }
}


void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void matrix_rotate_90(int order, int matrix[order][order])
{
    int i=0;
    int tot_levels = order/2, level = 0, last = order-1;


    while(level < tot_levels) {
        for(i = level; i < last; ++i) {
            swap((int *)&(matrix[level][i]), (int *)&(matrix[i][last]));
            swap((int *)&(matrix[level][i]), (int *)&(matrix[last][last-i+level]));
            swap((int *)&(matrix[level][i]), (int *)&(matrix[last-i+level][level]));
        }
        level++;
        last--;
    }
}


int main()
{

    make_matrix(size, matrix_nxn);
    printf("Original Matrix:\n");
    print_matrix(size, matrix_nxn);
    printf("\nRotated Matrix:\n");
    matrix_rotate_90(size, matrix_nxn);
    print_matrix(size, matrix_nxn);

    return 0;
}
