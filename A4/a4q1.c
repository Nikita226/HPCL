#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 40
#define threads 20
long long fib[N];
void parallel_fib(int n) 
{
    if (n < 2) 
    {
        fib[n] = n;
        return;
    }
    parallel_fib(n - 1);
    parallel_fib(n - 2);
    fib[n] = fib[n - 1] + fib[n - 2];
}
int main() 
{
    int n = N; 
    clock_t start=clock();
    #pragma omp parallel num_threads(threads)
    {
        #pragma omp
        parallel_fib(n);
    }
    clock_t end=clock();
    printf("\nFibonacci(%d) = %lld", n, fib[n]);
    printf("\nNumber of Threads: %d", threads);
    printf("\nTime: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
