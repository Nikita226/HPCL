#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 500

void sumLowerTriangularMatrices(int A[][N], int B[][N], int C[][N]) 
{
    int j, i;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
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
        {
            A[i][j] = value;
        }
    }
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            B[i][j] = value;
        }
    }
    sumLowerTriangularMatrices(A, B, C);
    clock_t end=clock();
    printf("\nSize of Matrix: %d x %d", N, N);
    printf("    Time taken: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    // printf("Matrix C:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            // printf("%d ", C[i][j]);
        }
        // printf("\n");
    }
    return 0;
}
