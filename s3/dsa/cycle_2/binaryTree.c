#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} node;

typedef struct queue
{
  int front;
  int back;
  int size;
  node *arr[100];
} queue;

// Queue
queue *createQueue();
void enqueue(queue *q, node *node);
node *dequeue(queue *q);

// Binary Tree
node *insert(node *root, int data);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);

int main()
{
  node *root = NULL;

  int ch;
  printf("1)Insert Node\n2)PreOrder Traversal\n3)InOrder Traversal\n4)PostOrder Traversal\n5)Exit");
  do
  {
    printf("\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      root = insert(root, x);
    }
    else if (ch == 2)
    {
      printf("\nPreOrder: ");
      preorder(root);
      printf("\n");
    }
    if (ch == 3)
    {
      printf("\nInOrder: ");
      inorder(root);
      printf("\n");
    }
    else if (ch == 4)
    {
      printf("\nPostOrder: ");
      postorder(root);
      printf("\n");
    }
  } while (ch != 5);
}
queue *createQueue()
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = -1;
  q->back = -1;
  q->size = 100;
  return q;
}

void enqueue(queue *q, node *node)
{
  if (q->front == -1 && q->back == -1)
  {
    q->front = 0;
    q->back = 0;
    q->arr[q->back] = node;
    return;
  }
  else if (q->back == q->size - 1)
  {
    printf("\nQueue overflow\n");
    return;
  }
  q->back++;
  q->arr[q->back] = node;
}

node *dequeue(queue *q)
{
  node *removed;
  if (q->back == q->front)
  {
    if (q->front == -1)
    {
      printf("\nQueue underflow!\n");
      return NULL;
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
  return removed;
}

node *insert(node *root, int data)
{
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  if (root == NULL)
  {
    root = new;
    return root;
  }
  queue *q = createQueue();
  enqueue(q, root);
  while (q->front != -1)
  {
    node *current = dequeue(q);
    if (current->left == NULL)
    {
      current->left = new;
      break;
    }
    else if (current->right == NULL)
    {
      current->right = new;
      break;
    }
    else
    {
      enqueue(q, current->left);
      enqueue(q, current->right);
    }
  }
  return root;
}

void preorder(node *root)
{
  if (root != NULL)
  {
    printf("%d, ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
  }
}

void postorder(node *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->data);
  }
}