#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct point
{
	int x;
	int y;
};

main()
{
	int i,j,n;
	struct point (*(*pnt))[1];
	time_t t1; //declare time variable
	srand((unsigned)time(&t1));
	printf("Enter no. of points: ");
	scanf("%d",&n);
	pnt = malloc(2*sizeof(struct point*));
	for(i=0;i<2;i++)
	{
		pnt[i] = malloc(n*sizeof(struct point));;
		for(j=0;j<n;j++)
		{
			(pnt[i][j])->x = rand()%100;
			(pnt[i][j])->y = rand()%100;
		}
	}
	
	for(i=0;i<2;i++)
	{
		printf("Display set%d points\n",i+1);
		for(j=0;j<n;j++)
			printf("%d %d\n",(pnt[i][j])->x,(pnt[i][j])->y);
	}	
}
