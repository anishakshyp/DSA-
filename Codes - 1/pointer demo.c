#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	time_t t;
	int i;
	float a[100];
	srand((unsigned)time(&t));
	printf("%d\n",RAND_MAX);
	for(i=0; i<100; i++)
	{
		a[i] = -1 + 2*((float)rand()/RAND_MAX);
	}
	for(i=0; i<100; i++)
	{
		printf("a[%d] = %f\n", i, a[i]);
	}
}
