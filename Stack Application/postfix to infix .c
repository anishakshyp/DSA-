#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node *createNode();
void push(struct node *);
struct node *pop();
void infixConvert(char []);
void display(struct node *);

struct node {
    char ch;
    struct node *left;
    struct node *right;
}*stack[MAX];
int top=-1;

void main() {
    char expr[MAX];
    printf("Enter the Expression : ");
    scanf("%s",expr);
    infixConvert(expr);
    printf("Infix Expression : ");
    display(pop(top));
}

struct node *createNode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    return newnode;
}

void infixConvert(char expr[]) 
{
    struct node *op1, *op2;
    struct node *newnode,*ptr,*n;
    int i;
    for(i=0;expr[i]!='\0';i++) {
        if(expr[i]>='a'&&expr[i]<='z'||expr[i]>='A'&&expr[i]<='Z') {
            newnode=createNode();
            newnode->ch=expr[i];
            newnode->left=NULL;
            newnode->right=NULL;
            push(newnode);
        }
        else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='^') 
		{
            op2=pop();
            op1=pop();
            newnode=createNode();
            newnode->ch=expr[i];
            newnode->right=op2;
            newnode->left=op1;
            ptr=newnode;
            while(ptr->left != NULL)
            	ptr=ptr->left;
            n=createNode();
            n->ch='(';
            n->left=NULL;
            n->right=NULL;
            ptr->left=n;
            ptr=newnode;
			while(ptr->right != NULL)
            	ptr=ptr->right;
            n=createNode();
            n->ch=')';
            n->left=NULL;
            n->right=NULL;
            ptr->right=n;
            push(newnode);
        }
    }
}
void push(struct node *ch) {
    if(top==MAX) 
	{
        printf("Full Stack");
        return;
    }
    stack[++top]=ch;
}
struct node *pop() {
    if(top==-1) {
        printf("Stack Empty");
    }
    else {
        return stack[top--];
    }
}
void display(struct node *temp) {
    if(temp==NULL) {
        return;
    }
    display(temp->left);
    printf("%c",temp->ch);
    display(temp->right);
}
