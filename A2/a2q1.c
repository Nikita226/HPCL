#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Include OpenMP library
#define SIZE 100000  // Define size of the vector
#define NUM_THREADS 4   // Define number of threads
#define CHUNK 1000
int main() {
    clock_t st=clock();
    omp_set_num_threads(NUM_THREADS);  // Set the number of threads
    int vector[SIZE];   // Create the vector and scalar
    int scalar = 50000; 
    // #pragma omp parallel for schedule(static,CHUNK) // Generate a vector in parallel
    #pragma omp parallel for schedule(dynamic,CHUNK)
    for (int i = 0; i < SIZE; i++) 
    {
        vector[i] = 100000;
    }
    // #pragma omp parallel for schedule(static,CHUNK)  // Perform vector-scalar addition in parallel
    #pragma omp parallel for schedule(dynamic,CHUNK)
    for (int i = 0; i < SIZE; i++) 
    {
        vector[i] += scalar;
    }
    //printf("Resulting Vector: ");      // Display the resulting vector
    for (int i = 0; i < SIZE; i++) {
       // printf("%d ", vector[i]);
    }
    clock_t et = clock();
    double tt = (double)(et-st) / CLOCKS_PER_SEC;
    printf("Num of threads: %d", NUM_THREADS);
    printf("\nTime required parallel program for Size %d and Chunk Size %d: %f\n",SIZE,CHUNK,tt);
    return 0;
}