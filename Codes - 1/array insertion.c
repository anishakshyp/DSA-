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
		printf("\nAre you continue to insert an element\n");
		printf("Enter your choice (y\\Y): ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch == 'y'||ch == 'Y')
		{
			n += 1;
			printf("Enter location/index of an array for new element: ");
			scanf("%d",&loc);
			printf("Enter the new element to be inserted into %d location: ",loc);
			scanf("%d",&data);
			p = realloc(p,1);
			for(i = n-1; i >= loc-1; --i)
			{
				*(p + i + 1) = *(p + i);
			}
			*(p + loc -1) = data;
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
