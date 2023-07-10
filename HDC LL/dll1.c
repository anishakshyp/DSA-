# include <stdio.h>
# include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
}*start;

void main()
{
	int m,n,i;
	void create_list(int);
	void display_list();
	start = NULL;
	printf("How many nodes you want : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element : ");
		scanf("%d",&m);
		create_list(m);
	}
	display_list();
}

void create_list(int num)
{
	struct node *q,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=num;
	tmp->next=NULL;
	if(start == NULL)
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


void display_list()
{
	struct node *p,*q;
	if(start == NULL)
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
