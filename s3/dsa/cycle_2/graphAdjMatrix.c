#include <stdio.h>
#include <stdlib.h>

// Graph
typedef struct Edge
{
  int from;
  int to;
} edge;
typedef struct Graph
{
  int v;
  int e;
  int **matrix;
} graph;

graph *createGraph(int size);
void insertEdge(graph *g, int from, int to);
void display(graph *g);
void dfs(graph *g, int start);
void bfs(graph *g, int start);

// Stack
typedef struct Stack
{
  int top;
  int size;
  int arr[100];
} stack;

stack *createStack();
void push(stack *s, int data);
int pop(stack *s);
void tos(stack *s);

// Queue
typedef struct queue
{
  int front;
  int back;
  int size;
  int arr[100];
} queue;

queue *createQueue();
void enqueue(queue *q, int data);
int dequeue(queue *q);

int main()
{
  graph *g = createGraph(20);

  /*
    1 - 2 - 4 - 6 - 8 - 10
    |
    3 - 5 - 7 - 9
  */

  insertEdge(g, 1, 2);
  insertEdge(g, 1, 3);
  insertEdge(g, 2, 1);
  insertEdge(g, 2, 4);
  insertEdge(g, 3, 5);
  insertEdge(g, 4, 6);
  insertEdge(g, 5, 7);
  insertEdge(g, 6, 8);
  insertEdge(g, 7, 9);
  insertEdge(g, 8, 9);
  insertEdge(g, 8, 10);
  display(g);
  dfs(g, 2);
  bfs(g, 2);
}

graph *createGraph(int size)
{
  graph *g = (graph *)malloc(sizeof(graph));
  g->v = size;
  g->e = 0;
  g->matrix = (int **)malloc(sizeof(int *) * (size + 1));
  for (int i = 0; i <= size; i++)
  {
    g->matrix[i] = (int *)malloc(sizeof(int) * (size + 1));
    for (int j = 0; j <= size; j++)
    {
      g->matrix[i][j] = 0;
    }
  }
  return g;
}

void insertEdge(graph *g, int from, int to)
{
  edge *new = (edge *)malloc(sizeof(edge));

  if (from > g->v || to > g->v)
  {
    printf("Edge doesn't exist!!\n");
    return;
  }
  g->matrix[from][to] = 1;
  g->e++;
}

void display(graph *g)
{
  printf("Nodes = %d, Edges = %d\n", g->v, g->e);
  for (int i = 0; i <= g->v; i++)
  {
    printf("%d : ", i);
    for (int j = 0; j <= g->v; j++)
    {
      if (g->matrix[i][j] == 1)
      {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

void dfs(graph *g, int start)
{
  printf("DFS\n");
  stack *s = createStack();
  int *visited = calloc(g->v + 1, sizeof(int));
  if (start > g->v)
  {
    printf("Not a valid node!!\n");
    return;
  }
  push(s, start);
  while (s->top != -1)
  {
    int node = s->arr[s->top];
    if (!visited[node])
    {
      printf("%d , ", node);
    }
    visited[node] = 1;
    int flag = 0;
    for (int i = 0; i <= g->v; i++)
    {
      if (g->matrix[node][i] != 0 && !visited[i])
      {
        push(s, i);
        flag = 1;
        break;
      }
    }
    if (!flag)
    {
      pop(s);
    }
  }
  free(visited);
  free(s);
  printf("\n");
}

void bfs(graph *g, int start)
{
  printf("BFS\n");
  queue *q = createQueue();
  int *visited = calloc(g->v + 1, sizeof(int));
  if (start > g->v)
  {
    printf("Not a valid node!!\n");
    return;
  }
  enqueue(q, start);
  while (q->front != -1)
  {
    int node = dequeue(q);
    if (visited[node])
    {
      continue;
    }
    visited[node] = 1;
    printf("%d , ", node);
    for (int i = 0; i <= g->v; i++)
    {
      if (g->matrix[node][i] != 0)
      {
        enqueue(q, i);
      }
    }
  }
  free(q);
  free(visited);
  printf("\n");
}
stack *createStack()
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = -1;
  s->size = 100;
  return s;
}

void push(stack *s, int data)
{
  // printf("Pushed - %d\n ", data);
  if (s->top == s->size - 1)
  {
    printf("Stack Overflow\n");
    return;
  }
  s->top++;
  s->arr[s->top] = data;
}

int pop(stack *s)
{
  if (s->top < 0)
  {
    printf("Stack underflow\n");
    return -1;
  }
  // printf("\nRemoved element = %d\n", s->arr[s->top]);
  s->top--;
  return s->arr[s->top + 1];
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
  // printf("Enqueue %d\n", data);
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

int dequeue(queue *q)
{
  int removed;
  if (q->back == q->front)
  {
    if (q->front == -1)
    {
      printf("\nQueue underflow!\n");
      return -1;
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
  q->size--;
  // printf("\nRemoved Element = %d\n", removed);
  return removed;
}
