#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d",x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes item %d",x);
	x--;
	++mutex;
}

int main()
{
	int n, i;
	printf("\n1. Press 1 for Producer"
		"\n2. Press 2 for Consumer"
		"\n3. Press 3 for Exit");
    
    clock_t start=clock();
    // #pragma omp critical
	#pragma omp parallel
	for (i = 1; i > 0; i++) 
	{

		printf("\nEnter your choice:");
		scanf("%d", &n);

		switch (n) {
		case 1:
			// If mutex is 1 and empty is non-zero, then it is possible to produce
			if ((mutex == 1) && (empty != 0)) {
				producer();
			}
			else {
				printf("Buffer is full!");
			}
			break;

		case 2:
			// If mutex is 1 and full is non-zero, then it is possible to consume
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!");
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
    clock_t end=clock();

    printf("Time taken : %f\n",(double)(end-start)/CLOCKS_PER_SEC);
}
