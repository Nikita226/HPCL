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
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            for (k = 0; k < N; k++) 
            {
                mul = A[i][k] * B[k][j];
                sum += mul;
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
    clock_t end=clock();
    printf("Time = %f seconds.\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
