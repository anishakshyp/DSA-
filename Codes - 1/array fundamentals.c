#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	printf("%u %u\n",arr,&arr);
	printf("%u %u\n",arr+1,&arr+1);
	printf("%d %d\n",*arr,*(&arr));
}
