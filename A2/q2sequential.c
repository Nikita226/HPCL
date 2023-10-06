// Calaculation of pi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100000
int main() 
{
    clock_t st=clock();
    double step = 1.0 / size;
    double pi_sum = 0.0;
    double pi_estimate = 0.0;
    double local_sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
        double x = (i + 0.5) * step;
        local_sum += 4.0 / (1.0 + x * x);
    }
    pi_sum += local_sum;
    pi_estimate = step * pi_sum;
    printf("\nSize: %d", size);
    printf("\nEstimated Pi: %f\n", pi_estimate);
    clock_t et = clock();
    double tt = (double)(et-st) / CLOCKS_PER_SEC;
    printf("\nTime required sequential program : %f\n", tt);
    printf("\n");
    return 0;
}
