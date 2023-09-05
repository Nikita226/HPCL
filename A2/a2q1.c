#include <stdio.h>
#include <omp.h>
#include <time.h>

#define size 1000
#define NUM_THREADS 100

void vectorScalarAdd(int* vector, int scalar) 
{
    #pragma omp parallel for private(scalar) num_threads(NUM_THREADS)
        #pragma omp nowait
        for (int i = 0; i < size; i++) 
        {
            vector[i] += scalar;
        }
}

int main() {
    int vector[size];
    int scalar = 5;

    for (int i = 0; i < size; i++) {
        vector[i] = i+10;
    }

    printf("Original Vector:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    clock_t start_time = clock();
    vectorScalarAdd(vector, scalar);
    
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

   
    printf("Vector after Scalar Addition:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    printf("Execution Time: %f seconds\n", elapsed_time);
    printf("Number of threads: %d \n",NUM_THREADS);
    printf("Input Size: %d",size);

    return 0;
}
