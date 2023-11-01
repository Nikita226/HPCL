#include <stdio.h>
#include <time.h>
#include <omp.h>
#define N 100
#define threads 4
int main() 
{ 
    clock_t start=clock();
	int arr[N]; 
    int value = 10;
    for (int i = 0; i < N; i++)
        arr[i] = value;
	int prefixSum[N];
    prefixSum[0] = arr[0];
    // #pragma omp critical
    #pragma omp parallel num_threads(threads)
    {
	    for (int i = 1; i < N; i++) 
		    prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    clock_t end=clock();
    printf("\nTime taken: %f",(double)(end-start)/CLOCKS_PER_SEC);
    printf("    Number of Threads: %d\n\n", threads);
    for(int i = 0; i < N; i++)
        printf("%d ", prefixSum[i]);
    return 0;
}
