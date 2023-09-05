#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 10

long long fib[N];

void parallel_fib(int n) {
    if (n < 2) {
        fib[n] = n;
        return;
    }

    #pragma omp task private(fib) 
    // printf("task1 by %d\n",n-1);
    parallel_fib(n - 1);

    #pragma omp task private(fib) 
    // printf("task2 by %d\n",n-2);
    parallel_fib(n - 2);

    #pragma omp taskwait

    fib[n] = fib[n - 1] + fib[n - 2];
}

int main() {
    int n = N; // Calculate Fibonacci(N)
    
    clock_t start=clock();
        // printf("No. of threads: %d\n",omp_get_num_threads());
    #pragma omp parallel num_threads(5)
    {
        #pragma omp
        parallel_fib(n);
    }
    clock_t end=clock();

    printf("Fibonacci(%d) = %lld\n", n, fib[n]);
    printf("Time: %f",(double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}
