#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}node;

int main()
{
	int d,i,n;
	void create_list(node **,int);
	node *create_list1(node *, int);
	void insert_node_end(node **);
	void insert_node_front(node **);
	void insert_node_between(node **, int);
	void delete_end_node(node **);
	void delete_front_node(node **);
	void delete_between_node(node **, int);
	void display_list(node *);
	
	node *start = NULL; 
	printf("Enter number of nodes of the list: ");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		printf("Enter node data: ");
		scanf("%d",&d);
		create_list(&start,d);
		//start = create_list1(start,d);
	}
	display_list(start);
	insert_node_end(&start);
	display_list(start);
	insert_node_front(&start);
	display_list(start);
	printf("\nEnter a node data after that new node to be inserted: ");
	scanf("%d",&n);
	insert_node_between(&start,n);
	display_list(start);
	printf("\nDelete last node\n");
	delete_end_node(&start);
	display_list(start);
	printf("\nDelete first node\n");
	delete_front_node(&start);
	display_list(start);
	printf("\nEnter a node data to be deleted: ");
	scanf("%d",&n);
	printf("Delete a node has data %d\n",n);
	delete_between_node(&start,n);
	display_list(start);
}

void create_list(node **p, int x)
{
	node *q = *p;
	if(q == NULL)
	{
		q = malloc(sizeof(node));
		q->data = x;
		q->next = NULL;
		*p = q;
	}
	else
	{
		while(q->next != NULL)
		{
			q = q->next;
		}
		q->next = malloc(sizeof(node));
		q = q->next;
		q->data = x;
		q->next = NULL;		
	}
}

node *create_list1(node *p, int x)
{
	node *tmp = p;
	if(tmp == NULL)
	{
		tmp = (node*)malloc(sizeof(node));
		tmp->data = x;
		tmp->next = NULL;
		return tmp;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = malloc(sizeof(node));
		tmp = tmp->next;
		tmp->data = x;
		tmp->next = NULL;
		return p;
	}
}

void display_list(node *p)
{
	while(p != NULL)
	{
		printf("%d->",p->data);
		p = p->next;
		if(p->next == NULL)
		{
			printf("%d",p->data);
			break;
		}
	}
}

void insert_node_end(node **p)
{
	node *t = *p;
	node *new_node = malloc(sizeof(node));
	printf("\nEnter a value for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	while(t->next)
		t = t->next;
	t->next = new_node;
}

void insert_node_front(node **p)
{
	node *new_node = malloc(sizeof(node));
	printf("\nEnter a value for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = *p;
	*p = new_node;
}

void insert_node_between(node **p, int d)
{
	node *t = *p;
	node *new_node = malloc(sizeof(node));
	printf("Enter a value for new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	while(t && t->data != d)
		t = t->next;
	if(t==NULL)
		printf("Invalid data");
	else
	{
		new_node->next = t->next;
		t->next = new_node;
	}
}	

void delete_end_node(node **p)
{
	node *t = *p;
	node *prev = NULL;
	while(t->next)
	{
		prev = t;
		t = t->next;
	}
	prev->next = NULL;
	free(t);
}

void delete_front_node(node **p)
{
	node *tmp = *p;
	*p = tmp->next;
	free(tmp);
}

void delete_between_node(node **p, int d)
{
	node *t = *p;
	node *prev = *p;
	while(t && t->data != d)
	{
		prev = t;
		t = t->next;
	}	
	if(t==NULL)
		printf("\nInvalid data to be deleted\n");
	else if(prev == t)
	{
		*p = prev->next;
		free(prev);
	}
	else
	{
		prev->next = t->next;
		free(t);
	}
}
