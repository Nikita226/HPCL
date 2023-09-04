// Calaculation of pi
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_SAMPLES 10000000

int main() {
    int num_threads[] = {1, 2, 4, 6, 8, 10}; // Number of threads to test
    int num_sizes[] = {1000, 900, 100000, 600}; // Different data sizes to test

    for (int size_index = 0; size_index < sizeof(num_sizes) / sizeof(num_sizes[0]); size_index++) {
        int size = num_sizes[size_index];
        double step = 1.0 / size;
        double pi_sum = 0.0;

        printf("Data size: %d\n", size);

        for (int thread_index = 0; thread_index < sizeof(num_threads) / sizeof(num_threads[0]); thread_index++) {
            int num_thread = num_threads[thread_index];
            double pi_estimate = 0.0;

            omp_set_num_threads(num_thread);

            #pragma omp parallel
            {
                double local_sum = 0.0;
                #pragma omp for
                for (int i = 0; i < size; i++) {
                    double x = (i + 0.5) * step;
                    local_sum += 4.0 / (1.0 + x * x);
                }
                #pragma omp critical
                pi_sum += local_sum;
            }

            pi_estimate = step * pi_sum;
            printf("Threads: %d, Estimated Pi: %f\n", num_thread, pi_estimate);
        }

        printf("\n");
    }

    return 0;
}
