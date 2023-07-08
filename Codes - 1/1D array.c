#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j,n,n1;
	int *p;
	printf("Enter array size: ");
	scanf("%d", &n);
	p=(int*)malloc(n*sizeof(int));
	//p=(int*)calloc(n,sizeof(int));
	printf("Enter numbers into array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i); 
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",*(p+i));
	}
	printf("\n");
	
	printf("Enter how many more elements what to add in array: "); 
	scanf("%d",&n1);
	p = realloc(p,n1);
	n1 = n + n1;
	printf("Enter numbers into array:\n");
	for(i=n;i<n1;i++)
	{
		scanf("%d",p+i); 
	}
	for(i=0;i<n1;i++)
	{
		printf("%d ",*(p+i));
	}
	printf("\n");
}
