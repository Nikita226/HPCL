#include <stdio.h>
#include <time.h>
#include <omp.h>
#define n 500
int main()
{
    clock_t start = clock();
    printf("The size of matrix: %d\n",n);
    int matrix[n][n], vector[n], result[n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            matrix[i][j]=2;

    for (int i = 0; i < n; i++)
        vector[i]=1;

    int x = 0;
    #pragma omp parallel
    // #pragma omp for
    // #pragma omp collapse(2)
    // #pragma omp nowait
    // #pragma omp critical
    for (int i = 0; i < n; i++) 
    {
        result[i] = 0;
        for (int j = 0; j < n; j++)
            result[i] += matrix[i][j] * vector[j];
    }

    // #pragma omp parallel reduction(+:x)
    // for (int i = 0; i < n; i++) 
    // {
    //     result[i] = 0;
    //     x = 0;
    //     for (int j = 0; j < n; j++)
    //         x += matrix[i][j] * vector[j];
    //     result[i] = x;
    // }
    clock_t end=clock();
    double t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSize of matrix: %d * %d",n, n);
    printf("\nSize of Vector: %d", n);
    printf("\nTime taken: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}