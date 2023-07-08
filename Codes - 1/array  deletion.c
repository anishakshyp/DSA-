#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,n,loc,data,*p;
	char ch;
	printf("Enter size of an array: ");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	printf("Enter elements in the array:\n");
	for(i=0;i<n;++i)
	{
		scanf("%d",p+i);
	}
	printf("Print elements of the array:\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",*(p+i));
	}
	while(1)
	{
		printf("\nAre you continue to delete an element\n");
		printf("Enter your choice (y\\Y): ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch == 'y'||ch == 'Y')
		{
			printf("Enter location/index of an array for deletion: ");
			scanf("%d",&loc);
			for(i = loc - 1; i < n; ++i)
			{
				*(p + i) = *(p + i + 1);
			}
			n -=1;
			p = realloc(p,n*sizeof(int));
			printf("Print elements of the array:\n");
			for(i=0;i<n;++i)
			{
				printf("%d ",*(p+i));
			}
		}
		else
		{
			break;
		}
	}
	
}
