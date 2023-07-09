#include<stdio.h>

// To force compiler to use 1 byte packaging
#pragma pack(1)// want to save members in byte form rather that cpu word size

struct abc{
	int i; // 4 bytes
	char ch; // 1 bytes
	double d; // 8 bytes
}; // Total memory allocated is 13 bytes

struct node
{
	int data;
	float *ptr;
};

int main()
{
	struct abc x; //x is a variable of abc structure. 
	struct node list; 
	printf("Size of Structure Variable is %d\n",sizeof(x));
	printf("Size of Structure Variable is %d\n",sizeof(list));
}
