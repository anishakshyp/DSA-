/* Program of single linked list*/
# include <stdio.h>
# include <stdlib.h>

typedef struct node{
		int info;
		struct node *next;
	}list;

list *head = NULL;

void create_list();
void insertAtBeg();
void insertAtPos();
void insertAtEnd();
void delNode();
void display_list();
void count_list();

int main()
{
	int choice;
	head = (list *)malloc(sizeof(list));
	head->info = 0;
	head->next = NULL;
	while(1)
	{
		printf("1. Create List\n");
		printf("2. Insert at begining\n");
		printf("3. Insert at end\n");
		printf("4. Insert at position\n");
		printf("5. Delete a node\n");
		printf("6. Display\n");
		printf("7. Count\n");
		printf("8. Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			create_list();
			break;
		 case 2:
			insertAtBeg();
			break;
		 case 3:
			insertAtEnd();
			break;
		 case 4:
			insertAtPos();
			break;
		 case 5:
			delNode();
			break;
		 case 6:
			display_list();
			break;
		 case 7:
			count_list();
			break;
		 case 8:
			exit(0);
			break;
		 default:
			printf("Wrong choice, Try again !!!\n");
		}/*End of switch */
	}/*End of while */
	return(0);
}

void create_list()
{
	int choice;
	list *p,*q;
	do{
		q = (list *)malloc(sizeof(list));
		printf("Enter node data: ");
		scanf("%d", &q->info);
		q->next = NULL;
		if(head->next == NULL) 
			head->next = q;
		else
		{   
			p = head->next;  
			while(p->next != NULL)
				p = p->next;
			p->next = q;
		}
		printf("Enter 1 to continue or 0 otherwise: ");
		scanf("%d",&choice);
	}while(choice);
}

void insertAtBeg()
{
	list *p;
	p = (list *)malloc(sizeof(list));
	printf("Enter data for new node: ");
	scanf("%d",&p->info);
	p->next = head->next;
	head->next = p;
}

void insertAtEnd()
{
	list *p,*q;
	p = head->next; //Address of first node
	q = (list *)malloc(sizeof(list));
	q->next = NULL;
	printf("Enter data for new node: ");
	scanf("%d", &q->info);
	while(p->next != NULL)
		p = p->next;
	p->next = q;
}

void insertAtPos()
{
	int pos, i;
	list *p,*q;
	printf("Enter node number after which new node to be inserted: ");
	scanf("%d", &pos);
	q = (list *)malloc(sizeof(list));
	q->next = NULL;
	printf("Enter new node value: ");
	scanf("%d", &q->info);
	p = head->next; //Address of first node
	for(i=0;i<pos-1;i++)
	{
		if(p == NULL)
		{
			printf("There are less than %d elements",pos);
			return;
		}
		else
		{
			p = p->next;
		}	
		q->next = p->next;
		p->next = q;
	}		
}

void delNode()
{
	int i,data;
	list *p,*q;
	printf("Enter the node data to be deleted: ");
	scanf("%d", &data);
	p = head->next; //Address of first node
	/*First element deleted*/
	if(p->info == data)
	{
		head->next = p->next;  
		free(p);
		return;
	}
	while(p->next != NULL) 
	{
		if(p->next->info == data)
		{
			q = p->next;
			p->next = q->next;
			free(q);
			return;
		}
		p = p->next;			
	}
	printf("Element %d not found\n",data);
}

void display_list()
{
	list *p = head->next; //Address of first node
	if(p == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is :\n");
	while(p->next != NULL)
	{
		printf("%d->", p->info);
		p = p->next;
	}
	printf("%d\n", p->info);
}

void count_list()
{
	list *p = head->next; //Address of first node
	int cnt = 0;
	while(p != NULL)
	{
		p = p->next;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}
