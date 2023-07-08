#include<stdio.h>
struct student{
		char name[10];
		int roll;
	}; //Array of five structures

int main()
{
	int i;
	struct student s[3];
	void display(struct student *, int);
	for(i=0; i<3; ++i)
	{
		printf("Enter Student details:\n");
		printf("Enter Student name: ");
		scanf("%s",s[i].name);
		printf("Enter Student roll no. :");
		scanf("%d",&s[i].roll);
	}
	display(s,3);
	return 0;
}

void display(struct student *p, int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("Name of the Student: %s\n",(p+i)->name);
		printf("Roll no. of the Student: %d\n",(p+i)->roll);
	}
}
