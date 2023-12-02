#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
  int front;
  int back;
  int size;
  int arr[100];
} queue;

queue *createQueue();
void enqueue(queue *q, int data);
void dequeue(queue *q);
void display(queue *q);

int main()
{
  queue *q = createQueue();
  int ch;
  printf("1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n");
  do
  {
    printf("Choice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\n");
      enqueue(q, x);
    }
    else if (ch == 2)
    {
      dequeue(q);
    }
    else if (ch == 3)
    {
      display(q);
    }
    else if (ch != 4)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 4);
}

queue *createQueue()
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = -1;
  q->back = -1;
  q->size = 100;
  return q;
}

void enqueue(queue *q, int data)
{
  if (q->front == -1 && q->back == -1)
  {
    q->front = 0;
    q->back = 0;
    q->arr[q->back] = data;
    return;
  }
  else if (q->back == q->size - 1)
  {
    printf("\nQueue overflow\n");
    return;
  }
  q->back++;
  q->arr[q->back] = data;
}

void dequeue(queue *q)
{
  int removed;
  if (q->back == q->front)
  {
    if (q->front == -1)
    {
      printf("\nQueue underflow!\n");
      return;
    }
    removed = q->arr[q->front];
    q->front = -1;
    q->back = -1;
  }
  else
  {
    removed = q->arr[q->front];
    q->front++;
  }
  printf("\nRemoved Element = %d\n", removed);
}

void display(queue *q)
{
  if (q->front == -1 && q->back == -1)
  {
    printf("\nQueue is empty!\n");
    return;
  }
  printf("\nQueue elements are\n");
  for (int i = q->front; i <= q->back; i++)
  {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}
