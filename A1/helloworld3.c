//%compiler: clang
//%cflags: -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
#pragma omp parallel num_threads(4)
    printf("%s\n", "Hello World");

    return 0;
}