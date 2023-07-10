# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}node;

typedef struct header{
	int count;
	node *next;
	node *tail;
}head;

head *start=NULL;

int main()
{
	int n;
	void create_list(int,node*); 
	void rec_disp_list(node*);
	void rec_reverse_disp_list(node*);
	void insertAtBegin();
	void insertAtEnd();
	void insertBefore();
	void insertAfter();
	void deleteNode(int);
	start = (head *)malloc(sizeof(head));
	start->next = NULL;
	start->count = 0;
	printf("Enter number of nodes of the list: ");
	scanf("%d",&n);
	create_list(n,start->next);
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	printf("\nDisplay reverse list\n");
	rec_reverse_disp_list(start->tail);
	insertAtBegin();
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	insertAtEnd();
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	insertBefore();
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	insertAfter();
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	printf("\nEnter a node data to be deleted from the list: ");
	scanf("%d",&n);
	deleteNode(n);
	printf("\nNumber of nodes in this list: %d\n",start->count);
	printf("\nDisplay list\n");
	rec_disp_list(start->next);
	printf("\nDisplay reverse list\n");
	rec_reverse_disp_list(start->tail);
	return 0;
}

void create_list(int x, node *ptr) 
{
	node *cur;
    if(x>0)
    {
    	cur = (node*)malloc(sizeof(node));
		printf ("Enter node data: ");
    	scanf ("%d",&cur->data);
    	cur->next = NULL;
    	cur->prev = NULL;
    	++start->count;
    	if (start->next == NULL)
    	{
        	start->tail = start->next = cur;
        	ptr = cur;
    	}
    	else
    	{
        	ptr->next = cur;
        	cur->prev = ptr;
        	ptr = ptr->next;
        	start->tail = ptr;
    	}   
    	create_list(x-1, ptr);
    }
}

void rec_disp_list(node *x)
{
	
	if(x->next == NULL)
	{
		printf("%d",x->data);
	}
	else
	{
		printf("%d->",x->data);
		rec_disp_list(x->next);
	}
}

void rec_reverse_disp_list(node *x)
{
	
	if(x->prev == NULL)
	{
		printf("%d",x->data);
	}
	else
	{
		printf("%d->",x->data);
		rec_reverse_disp_list(x->prev);
	}
}

void insertAtBegin()
{
	struct node *cur,*p;
	cur=(struct node *)malloc(sizeof(struct node));
	cur->prev = NULL;
	cur->next = NULL;
	++start->count;
	printf("\n\nEnter node value to be inserted at the begining: ");
	scanf("%d",&cur->data);
	
	p = start->next;
	cur->next=p; //1st Step
	p->prev=cur; //2nd Step
	start->next=cur; //3rd Step
}/*End of insertAtBegin()*/

void insertAtEnd()
{
	node *cur;
	cur=(struct node *)malloc(sizeof(struct node));
	cur->prev = NULL;
	cur->next = NULL;
	++start->count;
	printf("\n\nEnter node value to be inserted at the end: ");
	scanf("%d",&cur->data);
	cur->prev = start->tail;
	start->tail->next = cur;
	start->tail = cur;
}

void insertBefore()
{
	int n;
	node *cur,*p;
	cur=(struct node *)malloc(sizeof(struct node));
	cur->prev = NULL;
	cur->next = NULL;
	++start->count;
	printf("\n\nEnter a node value before which new node to be inserted: ");
	scanf("%d",&n);
	
	printf("\nEnter node value to be inserted before a node: ");
	scanf("%d",&cur->data);
	p = start->next;
	while(p && p->data != n)
		p = p->next;

	cur->next = p; //1st Step
	cur->prev = p->prev; //2nd Step
	p->prev->next = cur; //3rd Step
	p->prev = cur; //4th Step
}

void insertAfter()
{
	int n;
	node *cur,*p;
	cur=(struct node *)malloc(sizeof(struct node));
	cur->prev = NULL;
	cur->next = NULL;
	++start->count;
	printf("\n\nEnter a node value after which new node to be inserted: ");
	scanf("%d",&n);
	
	printf("\nEnter node value to be inserted before a node: ");
	scanf("%d",&cur->data);
	p = start->next;
	while(p && p->data != n)
		p = p->next;

	cur->next = p->next; //1st Step
	cur->prev = p; //2nd Step
	p->next->prev = cur; //3rd Step
	p->next = cur; //4th Step
}

void deleteNode(int x)
{
	node *p = start->next;
	while(p && p->data != x)
		p = p->next;
	if(p == NULL)
		printf("\nData not found in the list\n");
	else if(p == start->next) //Delete first node
	{
		start->next = p->next;
		free(p);
		--start->count;
	}
	else if(p == start->tail) //Delete last node
	{
		start->tail = p->prev;
		p->prev->next = NULL;
		free(p);
		--start->count;
	}
	else // Delete between node
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		--start->count;
	}
}
