#include<stdio.h>
int main()
{
	int num[100]={0};
	int i,j,n;
	printf("Enter size of an array which must be less than equal to 100: ");
	scanf("%d",&n);
	printf("Enter numbers onto the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(num[i]==num[j])
			{
				num[j]=-1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	for(i=0,j=0;i<n;i++)
	{
		if(num[i+1]!=-1)
		{
			j++;
			num[j]=num[i+1];
		}
	}

	printf("Display unique elements of an array:\n");
	for(i=0;i<j;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}
