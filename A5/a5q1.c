#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 300
#define chunk_size 300
#define threads 8

void sumLowerTriangularMatrices(int A[][N], int B[][N], int C[][N]) 
{
    int j,i;
    // #pragma omp parallel for private(i, j) schedule(static, chunk_size) num_threads(threads)
    #pragma omp parallel for private(i, j) schedule(dynamic, chunk_size) num_threads(threads)
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j <= i; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() 
{
    clock_t start=clock();
    int A[N][N];
    int B[N][N];
    int C[N][N]={0};
    int value = 40000;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j <= i; j++) 
            A[i][j] = value;
    }
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j <= i; j++) 
            B[i][j] = value;
    }
    sumLowerTriangularMatrices(A, B, C);
    clock_t end=clock();
    printf("\nChunk Size: %d", chunk_size);
    printf("    Number of Threads: %d", threads);
    printf("    Time taken: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
