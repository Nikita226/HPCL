#include<bits/stdc++.h>
#include<iostream>
#include <omp.h>
#include <time.h>
using namespace std;
#define NUM_thread 100
#define N 100
int main() {
    // Define the two input vectors
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> vector2 = {5, 4, 3, 2, 1};
    srand(1);
    // vector<int>vector1(N),vector2(N);
    // for(int i=0;i<N;i++)
    // {
    //     vector1[i]=rand()+200;
    //     vector2[i]=rand()*23;
    // }
    
    int product=0;
    clock_t start_time = clock();

    // Parallel section
    int i;
    #pragma omp parallel for num_threads(NUM_thread) reduction(+ : product) 
    for ( i = 0; i < vector1.size(); i++) {
        product += vector1[i] * vector2[i];
    }

    cout << " Scalar Product: " << product << endl;

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Execution Time: " << elapsed_time << " seconds\n";

    return 0;
}
