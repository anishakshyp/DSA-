#include<stdio.h>
int main()
{
	int i, a[5]={0};
	int b[5]={[0 ... 4]=1};
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d ",b[i]);
	}
}
