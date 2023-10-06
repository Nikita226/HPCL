#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000  // Define size of the vector
int main() {
    clock_t st=clock();
    int vector[SIZE];   // Create the vector and scalar
    int scalar =  50000;
    for (int i = 0; i < SIZE; i++) 
    {
        vector[i] = 100000;
    }
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
    printf("Time required sequential program for vector scalar addition size %d : %f \n",SIZE,tt);
    return 0;
}