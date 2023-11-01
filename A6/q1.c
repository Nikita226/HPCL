#include <stdio.h>
#include <time.h>
#include <omp.h>
#define N 100000
int main() 
{ 
    clock_t start=clock();
	int arr[N]; 
    int value = 10000;
    for (int i = 0; i < N; i++)
        arr[i] = value;
	int prefixSum[N];
    prefixSum[0] = arr[0];
    #pragma omp parallel
    {
	    for (int i = 1; i < N; i++) 
		    prefixSum[i] = prefixSum[i - 1] + arr[i];
    } 
    clock_t end=clock();
    printf("Time taken: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}