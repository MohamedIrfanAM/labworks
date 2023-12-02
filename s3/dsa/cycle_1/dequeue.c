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
void enqueueBack(queue *q, int data);
void enqueueFront(queue *q, int data);
void dequeueFront(queue *q);
void dequeueBack(queue *q);
void display(queue *q);

int main()
{
  queue *q = createQueue();
  int ch;
  printf("1)EnqueueFront\n2)DequeueFront\n3)EnqueueBack\n4)DequeuBack\n5)Display\n6)Exit\n");
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
      enqueueFront(q, x);
    }
    else if (ch == 2)
    {
      dequeueFront(q);
    }
    if (ch == 3)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\n");
      enqueueBack(q, x);
    }
    else if (ch == 4)
    {
      dequeueBack(q);
    }
    else if (ch == 5)
    {
      display(q);
    }
    else if (ch != 6)
    {
      // printf("\nInvalid option!\n");
    }
  } while (ch != 6);
}

queue *createQueue()
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = -1;
  q->back = -1;
  q->size = 100;
  return q;
}

void enqueueBack(queue *q, int data)
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

void enqueueFront(queue *q, int data)
{
  if (q->front == -1 && q->back == -1)
  {
    q->front = 0;
    q->back = 0;
    q->arr[q->back] = data;
    return;
  }
  else if (q->front == 0)
  {
    printf("\nQueue overflow\n");
    return;
  }
  q->front--;
  q->arr[q->front] = data;
}

void dequeueFront(queue *q)
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

void dequeueBack(queue *q)
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
    removed = q->arr[q->back];
    q->back--;
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
