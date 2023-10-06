#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define N 200
int main() 
{
    clock_t start_time = clock();
    int vector[N], scalar = 100000;
    for(int i = 0; i < N; i++)
    {
        vector[i] = 100000;
    }
    for (int i = 0; i < N; i++) 
    {
        vector[i] += scalar;
    }
    printf("\nChunk Size: %d", N);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f sec\n\n", elapsed_time);
    return 0;
}