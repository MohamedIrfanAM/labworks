#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
  int size;
  int length;
  int arr[100];
} queue;

queue *createQueue();
void enqueue(queue *q, int value);
void dequeue(queue *q);
void peak(queue *q);
void display(queue *q);

int main()
{
  queue *q = createQueue();
  int ch;
  printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n");
  do
  {
    printf("Choice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      enqueue(q, x);
    }
    else if (ch == 2)
    {
      dequeue(q);
    }
    else if (ch == 3)
    {
      peak(q);
    }
    else if (ch == 4)
    {
      display(q);
    }
    else if (ch != 5)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 5);
}

queue *createQueue()
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->length = 0;
  q->size = 100;
  return q;
}

void enqueue(queue *q, int value)
{
  if (q->length == q->size)
  {
    printf("\nQueue overflow\n");
  }
  int i = 0;
  for (i = 0; i < q->length; i++)
  {
    if (q->arr[i] < value)
    {
      break;
    }
  }
  for (int k = q->length; k > i; k--)
  {
    q->arr[k] = q->arr[k - 1];
  }
  q->arr[i] = value;
  q->length++;
  display(q);
}

void dequeue(queue *q)
{
  printf("\n%d dequeued\n", q->arr[0]);
  q->length--;
  for (int i = 0; i < q->length; i++)
  {
    q->arr[i] = q->arr[i + 1];
  }
  display(q);
}

void display(queue *q)
{
  for (int i = 0; i < q->length; i++)
  {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

void peak(queue *q)
{
  printf("\n%d\n", q->arr[0]);
}