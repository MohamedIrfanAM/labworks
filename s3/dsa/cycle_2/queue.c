#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node;

node *insertBegin(node *head, int data);
node *deleteEnd(node *head);
void display(node *head);

int main()
{
  node *head = NULL;
  int ch;
  printf("1)Display\n2)Enqueue\n3)Dequeue\n4)Exit");
  do
  {
    printf("\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      display(head);
    }
    else if (ch == 2)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      head = insertBegin(head, x);
      display(head);
    }
    else if (ch == 3)
    {
      head = deleteEnd(head);
      display(head);
    }
    else if (ch != 4)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 4);
}

node *insertBegin(node *head, int data)
{
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->next = head;
  temp->data = data;
  head = temp;
  return head;
}

void display(node *head)
{
  if (head == NULL)
  {
    printf("The Queue is empty!!\n");
    return;
  }
  printf("\n");
  node *current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

node *deleteEnd(node *head)
{
  if (head == NULL)
  {
    printf("List in empty!\n");
    return head;
  }
  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return head;
  }
  node *current = head;
  node *prev;
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  free(current);
  return head;
}