/* Program of double linked list*/
# include <stdio.h>
# include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
}*start;


void create_list(int num)
{
	struct node *q,*tmp;
	tmp= (struct node *)malloc(sizeof(struct node));
	tmp->info=num;
	tmp->next=NULL;
	if(start==NULL)
	{
		tmp->prev=NULL;
		start=tmp;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
			q=q->next;
		q->next=tmp;
		tmp->prev=q;
	}
}/*End of create_list()*/

void addatbeg(int num)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->prev=NULL;
	tmp->info=num;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
}/*End of addatbeg()*/

void addafter(int num,int c)
{
	struct node *tmp,*q;
	int i;
	q=start;
	for(i=0;i<c-1;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			printf("There are less than %d elements\n",c);
			return;
		}
	}
	tmp=(struct node *)malloc(sizeof(struct node) );
	tmp->info=num;
	q->next->prev=tmp;
	tmp->next=q->next;
	tmp->prev=q;
	q->next=tmp;
}/*End of addafter() */

void del(int num)
{
	struct node *tmp,*q;
	if(start->info==num)
	{
		tmp=start;
		start=start->next;  /*first element deleted*/
		start->prev = NULL;
		free(tmp);
		return;
	}
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->info==num)     /*Element deleted in between*/
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->info==num)    /*last element deleted*/
	{ 	tmp=q->next;
		free(tmp);
		q->next=NULL;
		return;
	}
	printf("Element %d not found\n",num);
}/*End of del()*/

void display()
{
	struct node *p,*q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	q=NULL;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ", p->info);
		q=p;
		p=p->next;
	}
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ", q->info);
		q=q->prev;
	}
	printf("\n");
}/*End of display() */

void count()
{ 	struct node *q=start;
	int cnt=0;
	while(q!=NULL)
	{
		q=q->next;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}/*End of count()*/

void rev()
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev; /*next of p2 changed to prev */
	}
	start=p1;
}/*End of rev()*/


int main()
{
	int choice,n,m,po,i;
	start=NULL;
	
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Add at begining\n");
		printf("3.Add after\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Count\n");
		printf("7.Reverse\n");
		printf("8.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
		 case 1:
			printf("How many nodes you want : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter the element : ");
				scanf("%d",&m);
				create_list(m);
			}
			break;
		 case 2:
			printf("Enter the element : ");
			scanf("%d",&m);
			addatbeg(m);
			break;
		 case 3:
			printf("Enter the element : ");
			scanf("%d",&m);
			printf("Enter the position after which this element is inserted : ");
			scanf("%d",&po);
			addafter(m,po);
			break;
		 case 4:
			printf("Enter the element for deletion : ");
			scanf("%d",&m);
			del(m);
			break;
		 case 5:
			display();
			break;
		 case 6:
			count();
			break;
		 case 7:
			rev();
			break;
		 case 8:
			exit(1);
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/
}/*End of main()*/
