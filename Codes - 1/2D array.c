#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 4
#define COL 5

int main()
{
	int i,j;
	time_t t;
	srand((unsigned)time(&t));
	int **p = NULL;
	p = (int **)malloc(ROW*sizeof(int*));
	if(p == NULL)
	{
		printf("Out of Memory");
		exit(0);
	}
	
	//Allocate memory location for 3-D Array and assign values to the elements of the 3-D Array
	for(i = 0; i < ROW; ++i)
	{
		p[i] = (int *)malloc(COL*sizeof(int));
		if(p[i] == NULL)
		{
			printf("Out of Memory");
			exit(0);
		}
		for(j = 0; j < COL; ++j)
		{
			p[i][j] = rand()%10;
		}
	}
	//Display the elements values of 2-D Array
	for(i = 0; i < ROW; ++i)
	{
		for(j = 0; j < COL; ++j)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}
