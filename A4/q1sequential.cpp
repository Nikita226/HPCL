#include <stdio.h>
#include <time.h>
#define N 50
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
    parallel_fib(n);
    clock_t end=clock();
    printf("\nFibonacci(%d) = %lld", n, fib[n]);
    printf("    Time: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
