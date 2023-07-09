#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LB 0
#define UB 10
#define SIZE 5

typedef struct point{
	int x;
	int y;
}point;

void main()
{
	int i;
	point p[SIZE];
	point *q = p; //q is a pointer to a point type structure
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<SIZE;++i)
	{
		printf("Enter x and y values of point p[%d]: ",i+1);
		//scanf("%d %d",&p[i].x, &p[i].y);
		scanf("%d %d",&(*(q+i)).x, &(*(q+i)).y);
		
	}
	printf("Print point coordinates x and y:\n");
	for(i=0;i<SIZE;++i)
	{
		printf("p[%d]-->(%d, %d)\n",i+1, (q+i)->x, (q+i)->y);
	}
}
