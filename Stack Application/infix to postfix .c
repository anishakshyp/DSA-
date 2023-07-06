/* Program for conversion of infix to postfix and evaluation of postfix.
It will take only single digit in expression */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 50

int eval_post();
void infix_to_postfix();
char infix[MAX], postfix[MAX];
int stack[MAX];
int top;

/* This function returns the precedence of the operator */
prec(char symbol )
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	}/*End of switch*/
}/*End of prec()*/

void push(long int symbol)
{
	if(top > MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	else
	{
		top=top+1;
		stack[top] = symbol;
	}
}/*End of push()*/

int pop()
{
	if (top == -1 )
	{
		printf("Stack is empty!!\n");
		exit(1);
	}
	else
		return (stack[top--]);
}/*End of pop()*/

int eval_post()
{
	int a,b,temp,result,len;
	int i;
	len=strlen(postfix);
	postfix[len]='#';

	for(i=0;postfix[i]!='#';i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push( postfix[i]-48 );
		else
		{
			a=pop();
			b=pop();

			switch(postfix[i])
			{
			case '+':
				temp=b+a; break;
			case '-':
				temp=b-a;break;
			case '*':
				temp=b*a;break;
			case '/':
				temp=b/a;break;
			case '%':
				temp=b%a;break;
			case '^':
				temp=pow(b,a);
			}/*End of switch */
			push(temp);
		}/*End of else*/
	}/*End of for */
	result=pop();
	return result;
}/*End of eval_post */

void infix_to_postfix()
{
	int i,p=0,type,precedence,len;
	char next ;

	stack[top]='#';
	len=strlen(infix);
	infix[len]='#';
	for(i=0; infix[i]!='#';i++)
	{
		switch(infix[i])
		{
			case '(':
				push(infix[i]);
				break;

			case ')':
				while((next = pop()) != '(')
					postfix[p++] = next;

				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				precedence = prec(infix[i]);
				while(stack[top]!='#' && precedence<= prec(stack[top]))
					postfix[p++] = pop();
				push(infix[i]);
				break;
			default: /*if an operand comes */
			     postfix[p++] = infix[i];
		}/*End of switch */
	}/*End of for */
	while(stack[top]!='#')
		postfix[p++] = pop();
	postfix[p] = '\0' ; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/


main()
{
	long int value;
	char choice='y';
	while(choice == 'y')
	{
		top = 0;
		printf("Enter infix : ");
		fflush(stdin);
		gets(infix);
		infix_to_postfix();
		printf("Postfix : %s\n",postfix);
		value=eval_post();
		printf("Value of expression : %ld\n",value);
		printf("Want to continue(y/n) : ");
		scanf("%c",&choice);
	}
}/*End of main()*/
