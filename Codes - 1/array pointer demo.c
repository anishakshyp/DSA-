#include<stdio.h>
int main()
{
	int a[] = {1,2,3,4,5};
	int (*p)[5] = &a;
	printf("%u---%u",p,p+1);
	return 0;
}
