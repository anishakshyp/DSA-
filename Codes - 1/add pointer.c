#include<stdio.h>
int add(int a, int b)
{
	return (a+b);
}

int main()
{
	int a=100,b=200,c=0;
	int (*p)(int,int); //pointer to function
	p=add;
	c=p(a,b);
	printf("Sum=%d\n",c);
}
