#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    // Varying matrix sizes
    srand(0);
    int sizes[] = {50, 100, 200, 300};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Varying thread counts
    int num_threads[] = {1, 2, 4, 8};
    int num_thread_counts = sizeof(num_threads) / sizeof(num_threads[0]);

    for (int size_idx = 0; size_idx < num_sizes; size_idx++) 
    {
        int size = sizes[size_idx];
        int A[size][size];
        int B[size][size];
         for (int i = 0; i < size; i++) 
         {
            for (int j = 0; j < size; j++) 
            {
                A[i][j] = rand() % 100;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) 
            {
                B[i][j] = rand() * 13;
            }
        }
        
       int C[size][size];

        printf("Matrix Size: %d x %d\n", size, size);

        for (int thread_idx = 0; thread_idx < num_thread_counts; thread_idx++) 
        {
            int num_thread = num_threads[thread_idx];
            omp_set_num_threads(num_thread);
            clock_t start_time = clock();

            #pragma omp parallel for
            for (int i = 0; i < size; i++) 
            {
                for (int j = 0; j < size; j++) 
                {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }

            clock_t end_time = clock();
            double execution_time =(double)( end_time - start_time)/CLOCKS_PER_SEC;

            printf("Threads: %d, Execution Time: %f seconds\n", num_thread, execution_time);
        }

        for (int i = 0; i < size; i++) 
        {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }
    return 0;
}
