#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 300

int A[N][N];
int B[N][N];
int C[N][N];

int main() 
{
    clock_t start=clock();
    int i,j,k;
    for (i= 0; i< N; i++)
    for (j= 0; j< N; j++)
    {
        A[i][j] = 2;
        B[i][j] = 2;
    }
    int sum = 0, mul = 0;
    // #pragma omp parallel for private(i,j,k) shared(A,B,C) reduction(+:sum)
    // #pragma omp parallel for private(i,j,k) shared(A,B,C) ordered reduction(+:sum)
    #pragma omp for collapse(2)
    for (i = 0; i < N; ++i) 
    {
        for (j = 0; j < N; ++j) 
        {
            for (k = 0; k < N; ++k) 
            {
                mul = A[i][k] * B[k][j];
                sum += mul;
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
    clock_t end=clock();
    // printf("\nUsing reduction clause");
    // printf("\nUsing ordered reduction clause");
    printf("\nUsing collapse clause");
    printf("Time = %f sec\n\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
