#include <stdio.h>

typedef struct _node
{
   char element;
   struct _node *next;
}node;

typedef struct {
   node *front;
   node *back;
}queue;

queue init ()
{
   queue Q;

   /* Create the dummy node */
   Q.front = (node *)malloc(sizeof(node));
   Q.front -> element = ' ';
   Q.front -> next = NULL;
   Q.back = Q.front;
   return Q;
}

int isEmpty(queue Q)
{
   return (Q.front == Q.back);
}

queue enqueue(queue Q , char ch)
{
   node *C;
   	if (isFull(Q)) 
	{
      	fprintf(stderr,"enqueue: Queue is full\n");
      	return Q;
   	}

   	/* Create new node */
   	C = (node *)malloc(sizeof(node));
   	C -> element = ch;
   	C -> next = NULL;

   	/* Adjust the back of queue */
   	Q.back -> next = C;
   	Q.back = C;

   	return Q;
}

queue dequeue(queue Q)
{
   if (isEmpty(Q)) 
   	{
      	fprintf(stderr,"dequeue: Queue is empty\n");
      	return Q;
   	}

   	/* Make the front of the queue the new dummy node */
   	Q.front = Q.front -> next;
   	Q.front -> element = '\0';

   	return Q;
}

void print ( queue Q )
{
   node *G;

   G = Q.front -> next;
   while (G != NULL) {
      printf("%c", G -> element);
      G = G -> next;
   }
}

int main()
{
   queue Q;

   Q = init(); printf("Queue elements: "); 
   print(Q); 
   printf("\n");
   Q = enqueue(Q,'h'); 
   printf("Queue elements: "); 
   print(Q); 
   printf("\n");
   Q = enqueue(Q,'w'); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = enqueue(Q,'r'); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = enqueue(Q,'c'); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Current queue : "); 
   print(Q); 
   printf("\n");
}
