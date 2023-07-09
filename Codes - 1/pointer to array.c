#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int main()
{	
	int i,j;
	int (*p)[3]; //Variable no. of rows and fixed no. of columns
	int *q[3]; //Array of pointers
	int **s; //variable no. rows and variable no. columns
	p = (int(*)[3])malloc(3*3*sizeof(int));//pointer to an array
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<3;++i)
	{
		q[i] = (int*)malloc(3*sizeof(int));
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			scanf("%d",&q[i][j]);
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			printf("%d ",q[i][j]);
		}
		printf("\n");
	}
	
	s = (int**)malloc(3*sizeof(int*));
	for(i=0;i<3;++i)
	{
		s[i]= (int*)malloc(3*sizeof(int));
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			scanf("%d",&s[i][j]);
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
}
