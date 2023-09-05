#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define VECTOR_SIZE 1000

int main() {
    srand(23);
    int i;
    double vector[VECTOR_SIZE];
    double scalar = 20387.0;

    // Initialize the vector with some values (for demonstration purposes)
    for (i = 0; i < VECTOR_SIZE; i++) {
        vector[i] = rand()*20;
    }

    // printf("Original Vector:\n");
    // for (i = 0; i < VECTOR_SIZE; i++) {
    //     printf("%lf ", vector[i]);
    // }
    printf("\n");

    // Varying chunk sizes for STATIC schedule
    int chunk_sizes[] = {1, 2, 4, 8, 16, 32, 64};

    for (int j = 0; j < sizeof(chunk_sizes) / sizeof(chunk_sizes[0]); j++) {
        int chunk_size = chunk_sizes[j];

        // Reset the vector to its original values
        for (i = 0; i < VECTOR_SIZE; i++) {
            vector[i] = 1.0;
        }

        clock_t start_time = clock();

        #pragma omp parallel for schedule(dynamic, chunk_size)
        for (i = 0; i < VECTOR_SIZE; i++) {
            vector[i] += scalar;
        }

        clock_t end_time = clock();
        double execution_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

        printf("Chunk Size: %d, Execution Time: %lf seconds\n", chunk_size, execution_time);

        // printf("Modified Vector (Chunk Size %d):\n", chunk_size);
        // for (i = 0; i < VECTOR_SIZE; i++) {
        //     printf("%lf ", vector[i]);
        // }
        printf("\n");
    }

    return 0;
}
