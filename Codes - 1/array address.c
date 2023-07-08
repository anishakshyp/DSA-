#include<stdio.h>
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	printf("Address of a1 = %u\n",&a);
	printf("Address of a2 = %u\n",&a+1);
	printf("Address of a3 = %u\n",&a+2);
}
