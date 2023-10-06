#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define NUM_thread 100
#define N 2000
// 10/100  100 1000 2000
int main() 
{
    clock_t start_time = clock();
    int vector1[N], vector2[N];
    for(int i = 0; i < N; i++)
    {
        vector1[i] = 900;
        vector2[i] = 900;
    }
    int product=0;
    int i;
    // Parallel section
    // #pragma omp parallel for num_threads(NUM_thread) reduction(+ : product) 
    #pragma omp for nowait
    for ( i = 0; i < N; i++) 
    {
        product += vector1[i] * vector2[i];
    }
    printf("\nScalar Prodcut: %d", product);
    printf("\nNum threads: %d", NUM_thread);
    printf("\nSize: %d", N);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f sec\n\n", elapsed_time);
    return 0;
}
