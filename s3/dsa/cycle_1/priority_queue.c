#include <stdlib.h>
#include <stdio.h>

typedef struct item
{
  int value;
  int priority;
} item;

typedef struct queue
{
  int back;
  int size;
  item items[100];
} queue;

queue *createQueue();
void enqueue(queue *q, int value, int priority);
void dequeue(queue *q);
void peak(queue *q);
void display(queue *q);

int main()
{
  queue *q = createQueue();
  int ch;
  do
  {
    printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x, y;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\n");
      printf("\nEnter the priority: ");
      scanf("%d", &y);
      printf("\n");
      enqueue(q, x, y);
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
  q->back = -1;
  q->size = 100;
  return q;
}

void heapify(queue *q, int loc)
{
  int left = (2 * loc);
  int right = left + 1;
  int largest = loc;
  if (left <= q->back && q->items[left].priority > q->items[largest].priority)
  {
    largest = left;
  }
  if (right <= q->back && q->items[right].priority > q->items[largest].priority)
  {
    largest = right;
  }
  if (largest != loc)
  {
    item k = q->items[loc];
    q->items[loc] = q->items[largest];
    q->items[largest] = k;
    heapify(q, largest);
  }
}

void enqueue(queue *q, int value, int priority)
{
  if (q->back == q->size - 1)
  {
    printf("\nQueue Oveflow\n");
    return;
  }
  q->back++;
  q->items[q->back].priority = priority;
  q->items[q->back].value = value;
  int back = q->back;
  int parent = back / 2;
  while (back >= 0)
  {
    if (q->items[parent].priority < q->items[back].priority)
    {
      item k = q->items[parent];
      q->items[parent] = q->items[back];
      q->items[back] = k;
    }
    else
    {
      heapify(q, back);
      break;
    }
    back = parent;
    parent /= 2;
  }
}

void dequeue(queue *q)
{
  if (q->back < 0)
  {
    q->back = -1;
    printf("\nQueue underflow!\n");
    return;
  }
  q->items[0] = q->items[q->back];
  q->back--;
  heapify(q, 0);
}

void peak(queue *q)
{
  printf("value = %d, priority = %d\n", q->items[0].value, q->items[0].priority);
}

void display(queue *q)
{
  queue *k = (queue *)malloc(sizeof(queue));
  k->back = q->back;
  k->size = 100;
  for (int i = 0; i <= q->back; i++)
  {
    k->items[i] = q->items[i];
  }
  printf("\n");
  for (int i = 0; i <= q->back; i++)
  {
    peak(k);
    dequeue(k);
  }
  printf("\n");
  free(k);
}