#include <stdio.h>

#define MAXLEN 5

typedef struct {
   	char element[MAXLEN];
   	int front;
   	int back;
}queue;

queue initQueue()
{
   	queue Q;
   	Q.front = 0;
   	Q.back = MAXLEN - 1;
   	return Q;
}

int isEmpty(queue Q)
{
   	return (Q.front == (Q.back + 1) % MAXLEN);
}

int isFull (queue Q)
{
   	return (Q.front == (Q.back + 2) % MAXLEN);
}

queue enqueue (queue Q , char ch)
{
   	if (isFull(Q)) 
   	{
      	fprintf(stderr,"enqueue: Queue is full\n");
      	return Q;
   	}
   	++Q.back;
   	if (Q.back == MAXLEN) 
	   	Q.back = 0;
   	Q.element[Q.back] = ch;
   	return Q;
}

queue dequeue (queue Q)
{
   	if (isEmpty(Q)) 
	{
      fprintf(stderr,"dequeue: Queue is empty\n");
      return Q;
   	}
   	++Q.front;
   	if (Q.front == MAXLEN) 
   		Q.front = 0;
   	return Q;
}

void display(queue Q)
{
   int i;

   	if (isEmpty(Q)) 
   		return;
   	i = Q.front;
   	while(1) 
	{
      	printf("%c", Q.element[i]);
      	if (i == Q.back) 
			break;
      	if (++i == MAXLEN) 
		  	i = 0;
   	}
}

int main ()
{
   queue Q;

   Q = initQueue(); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = enqueue(Q,'h');
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = enqueue(Q,'w'); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = enqueue(Q,'r'); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = enqueue(Q,'c'); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
   Q = dequeue(Q); 
   printf("Queue elements: "); 
   display(Q); 
   printf("\n");
}
