#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 100

int A[N][N];
int B[N][N];
int C[N][N];

int main() 
{
    int i,j,k;
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	    {
            A[i][j] = 2;
            B[i][j] = 2;
	    }

    clock_t start=clock();
    // int mul=0,sum=0;
    #pragma omp parallel for private(i,j,k) shared(A,B,C) collapse(3)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                // mul=A[i][k] * B[k][j];
                // sum+=mul;
                C[i][j] += A[i][k] * B[k][j];
            }
            // C[i][j]=sum;
            // sum=0;
        }
    }


    clock_t end=clock();
    printf("elapsed time = %f seconds.\n", (double)(end-start)/CLOCKS_PER_SEC);

    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}