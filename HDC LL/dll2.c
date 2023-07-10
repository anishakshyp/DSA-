# include <stdio.h>
# include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
}*head,*tail;

void main()
{
	void create_list();
	void display_list();
	head = tail = NULL;
	create_list();
	display_list();
}

void create_list()
{
	struct node *temp,*new;
	int choice;
	do{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d",&new->info);
		new->prev = NULL;
		new->next = NULL;
		if(head == NULL)
		{
			head = temp = new;
		}
		else
		{
			temp->next = new;
			new->prev = temp;
			temp = new;
		}
		tail = new;
		printf("Enter 1 to continue or 0 to stop: ");
		scanf("%d",&choice);
	}while(choice);
}

void display_list()
{
	struct node *p,*q;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head;
	q=tail;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ", p->info);
		p=p->next;
	}
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ", q->info);
		q=q->prev;
	}
	printf("\n");
}
