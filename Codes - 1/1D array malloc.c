#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 2
void main()
{
	int i,j,n;
	//int *p;
	int a[] = {1, 2, 3, 4, 5, 6};
	int (*q)[COL]= (int(*)[COL])&a;
//	printf("Enter array size: ");
//	scanf("%d", &n);
	//p=(int*)calloc(n,sizeof(int));
	//printf("Enter numbers into array\n");
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",p+i); 
//	}
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",*(p+i));
//	}
//	p = realloc(p,5);
//	n = n + 5; 
//	printf("\n");
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",*(p+i));
//	}
	//printf("\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d ",*(*(q+i)+j));
		}
		printf("\n");
	}
}
