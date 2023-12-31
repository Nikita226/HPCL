#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 200
// #define chunk_size 1
int main() 
{
    clock_t start_time = clock();
    int vector[N], scalar = 100000;
    for(int i = 0; i < N; i++)
    {
        vector[i] = 100000;
    }
    int i;
    // Parallel section
    // #pragma omp parallel for schedule(static, chunk_size)
    // #pragma omp parallel for schedule(dynamic, chunk_size)
    #pragma omp for nowait
    for ( i = 0; i < N; i++) 
    {
        vector[i] += scalar;
    }
    // printf("\nChunk Size: %d ", chunk_size);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f sec\n\n", elapsed_time);
    return 0;
}