//This program implements different way of passing 2D array to function

#include<stdio.h>
#define ROW 3
#define COL 2
main ( )
{
	int arr[3][2] = {
			{ 10 , 100 },
			{ 20 , 200 },
			{ 30 , 300 }
			  };
	int i , j;
	//void display1(int [][COL]);
	//void display2(int *);
	//void display3(int (*)[]);
	void display4(int (*)[ROW][COL]);
	//display1(arr); //Passing argument as array
	//display2((int *)arr); //Passing argument as a pointer
	//display3(arr); //passing argument as pointer to an array
	display4(&arr); //passing argument as pointer to 2D array
}



//void display1(int a[][COL])
//{
//	int i,j;
//	for ( i = 0 ; i < ROW ; i++)
//	{
//		printf ("\n");
//		for ( j=0;j< COL;j++)
//		{
//			printf ("value = %d\t", a[i][j]);
//		}
//	}
//}



//void display2(int *a)
//{
//	int i,j;
//	for ( i = 0 ; i < ROW ; i++)
//	{
//		printf ("\n");
//		for ( j=0;j< COL;j++)
//		{
//			printf ("value = %d\t", *((a+i*COL)+j));
//		}
//	}
//}



//void display3(int (*a)[COL])
//{
//	int i,j;
//	for ( i = 0 ; i < ROW ; i++)
//	{
//		printf ("\n");
//		for ( j=0;j< COL;j++)
//		{
//			printf ("value = %d\t", a[i][j]);
//		}
//	}
//}


void display4(int (*a)[ROW][COL])
{
	int i,j;
	for ( i = 0 ; i < ROW ; i++)
	{
		printf ("\n");
		for ( j=0;j< COL;j++)
		{
			printf ("value = %d\t", (*a)[i][j]);
		}
	}
}
