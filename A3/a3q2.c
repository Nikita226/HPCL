#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define size 400
#define num_thread 8

int main() 
{
    clock_t start_time = clock();
    int A[size][size];
    int B[size][size];
    // size of matrix {50, 100, 200, 300};
    // num threads {1, 2, 4, 8};
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
           A[i][j] = 100;
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
           B[i][j] = 100;
    } 
    int C[size][size];
    omp_set_num_threads(num_thread);
    #pragma omp parallel for
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("\nMatrix Size: %d x %d\n", size, size);
    clock_t end_time = clock();
    double execution_time =(double)( end_time - start_time)/CLOCKS_PER_SEC;
    printf("Threads: %d, Execution Time: %f seconds\n\n", num_thread, execution_time);
    return 0;
}
