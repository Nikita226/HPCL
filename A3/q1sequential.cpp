#include<bits/stdc++.h>
#include<iostream>
#include <time.h>
using namespace std;
#define N 100
int main() 
{
    clock_t start_time = clock();
    vector<int>vector1(N),vector2(N);
    for(int i=0;i<N;i++)
    {
        vector1[i]=900;
        vector2[i]=900;
    }
    long long int product=0;
    int i;
    for (i = 0; i < N; i++) 
    {
        product += vector1[i] * vector2[i];
    }
    cout << "\nScalar Product: " << product;
    cout << "\nSize: " << N;
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nExecution Time: " << elapsed_time << " seconds\n";
    return 0;
}
