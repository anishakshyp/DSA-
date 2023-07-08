 #include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j;
	int a[8] = {10,20,30,40,50,60,70,80};
	int (*p)[4] = (int(*)[2])&a;
	for(i=0;i<4;i++) //Row
	{
		for(j=0;j<2;j++) //Column
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}
