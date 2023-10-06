// Calaculation of pi
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define NUM_THREADS 4   // Define number of threads
#define CHUNK 10000
#define size 100000
int main() 
{
    clock_t st=clock();
    double step = 1.0 / size;
    double pi_sum = 0.0;
    double pi_estimate = 0.0;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        double local_sum = 0.0;
        #pragma omp for
        for (int i = 0; i < size; i++) 
        {
            double x = (i + 0.5) * step;
            local_sum += 4.0 / (1.0 + x * x);
        }
        #pragma omp critical
        pi_sum += local_sum;
    }
    pi_estimate = step * pi_sum;
    printf("\nSize: %d", size);
    printf("\nThreads: %d", NUM_THREADS);
    printf("\nEstimated Pi: %f\n", pi_estimate);
    clock_t et = clock();
    double tt = (double)(et-st) / CLOCKS_PER_SEC;
    printf("\nTime required parallel program : %f\n", tt);
    printf("\n");
    return 0;
}
