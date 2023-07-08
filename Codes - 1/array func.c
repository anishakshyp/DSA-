#include<stdio.h>
int main()
{
	int i,j,row,col;
	//int mat[][3]={{0},{0},{0}};
	int mat[][3]={{1},{0,1},{0,0,1}};
	int arr[100][100];

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("%d %d %d %d\n",mat,&mat,mat[0],&mat[0][0]);
	printf("%d %d %d %d\n",mat+1,mat[0]+3,mat[1],&mat[1][0]);
	printf("%d %d %d %d\n",mat+2,mat[0]+6,mat[2],&mat[2][0]);	
	printf("Enter number of rows and columns of a 2D array: ");
	scanf("%d%d",&row,&col);
	printf("Enter elements of [%d x %d] array\n",row,col);
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Display 2D array\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}		
}
