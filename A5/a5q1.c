#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 4

void sumLowerTriangularMatrices(int A[][N], int B[][N], int C[][N]) {
    clock_t start_time = clock();
    #pragma omp parallel for 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    clock_t end_time = clock();
    printf("Total time: %d in seconds\n", end_time - start_time);
}

int main() {
    int A[N][N] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };

    int B[N][N] = {
        {10, 0, 0, 0},
        {9, 8, 0, 0},
        {7, 6, 5, 0},
        {4, 3, 2, 1}
    };

    int C[N][N]={0};
    clock_t start_time = clock();
    sumLowerTriangularMatrices(A, B, C);

    printf("Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}