#include<stdio.h>
#include<stdlib.h>

typedef int (*t)[3];

void main()
{
	int i,j,k;
	int (*(*s))[3];
	
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[2][3] = {{11,22,33},{44,55,66}};

	t *p = (t*)malloc(2*sizeof(t));
	p[0] = a;
	p[1] = b;
	printf("%d\n",p[1][0][2]);
	
	s = malloc(2*sizeof(int*));
	s[0] = malloc(6*sizeof(int));
	s[1] = malloc(6*sizeof(int));
	for(i=0;i<2;++i)
	{
		printf("Enter %d 2D array\n",i+1);
		for(j=0;j<3;++j)
		{
			for(k=0;k<3;++k)
			{
				scanf("%d",&s[i][j][k]);
			}
		}
	}
	printf("%d ",s[1][0][2]);
}
