#include<stdio.h>
main ( )
{
	int arr[3][2] = {
			{ 10 , 100 },
			{ 20 , 200 },
			{ 30 , 300 }
			  };
	int i , j;
	//int (*p)[3][2]=&arr;
	//int *q = (int *)arr;
	int (*r)[2] = arr;
	for ( i = 0 ; i < 3 ; i++)
	{
		printf ("\n");
		for ( j=0;j< 2;j++)
		{
			//printf ("value = %d\t", (*p)[i][j]);
			//printf ("value = %d\t", *((q+i*2)+j));
			printf ("value = %d\t", r[i][j]);
		}
	}
}
