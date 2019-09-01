#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int matrix_size = n + n -1;
    for(int row=0; row < matrix_size; ++row) {
        for(int col=0; col < matrix_size; ++col) {
            int r = row;
            int c = col;
            int min_r = r < matrix_size-r ? r : matrix_size - r-1;
            int min_c = c < matrix_size-c ? c : matrix_size - c-1;
            int min = min_r < min_c ? min_r : min_c;
            //printf("%d ", n-min);
            printf("r:%d, c:%d, min_r:%d, min_c:%d print:%d\n", r, c, min_r, min_c, n-min);
        }
        printf("\n");
    }
    return 0;
}
