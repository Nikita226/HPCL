#include <omp.h>
#include <pthread.h>
#include <stdio.h>

int main() {
    int N;
    printf("Enter the size of vector: ");
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = 10;

    int B[N];
    for (int i = 0; i < N; i++)
        B[i] = 20;

    int C[N];
    for (int i = 0; i < N; i++)
        C[i] = 0;
    double stime = omp_get_wtime();

    int numThreads;
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads); 
    omp_set_num_threads(numThreads);

    #pragma omp parallel for reduction(+ : C)
    for (int i = 0; i < N; i++) 
    {
        C[i] = A[i] + B[i];
    }

    for (int i = 0; i < N; i++) 
    {
        printf("%d ", C[i]);
    }

    double etime = omp_get_wtime();
    double time = etime - stime;
    printf("\n\nSize of Vector: %d", N);
    printf("\nNumber of Threads: %d", numThreads);
    printf("\nTime taken is %f\n", time);
    printf("\n");
    return 0;
}
