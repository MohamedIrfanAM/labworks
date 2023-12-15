#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node;

node *insertBegin(node *head, int data);
node *insertEnd(node *head, int data);
node *insertIndex(node *head, int data, int index);
node *deleteBegin(node *head);
node *deleteEnd(node *head);
node *deleteIndex(node *head, int index);
void display(node *head);

int main()
{
  node *head = NULL;
  int ch;
  printf("1)Display\n2)InsertBegin\n3)InsertEnd\n4)InsertIndex\n5)deleteBegin\n6)deleteEnd\n7)deleteIndex\n8)Exit\n");
  do
  {
    printf("Choice: ");
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
      printf("\n");
      head = insertBegin(head, x);
    }
    else if (ch == 3)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\n");
      head = insertEnd(head, x);
    }
    else if (ch == 4)
    {
      int x, i;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\nEnter the index: ");
      scanf("%d", &i);
      printf("\n");
      head = insertIndex(head, x, i);
    }
    else if (ch == 5)
    {
      head = deleteBegin(head);
    }
    else if (ch == 6)
    {
      head = deleteEnd(head);
    }
    else if (ch == 7)
    {
      int i;
      printf("\nEnter the index: ");
      scanf("%d", &i);
      printf("\n");
      head = deleteIndex(head, i);
    }
    else if (ch != 8)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 8);
}

node *insertBegin(node *head, int data)
{
  /*printf("%d",data);*/
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->next = head;
  temp->data = data;
  head = temp;
  return head;
}

node *insertEnd(node *head, int data)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
    return head;
  }
  node *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = temp;
  return head;
}

void display(node *head)
{
  if (head == NULL)
  {
    printf("The list is empty!!\n");
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

node *insertIndex(node *head, int data, int index)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  if (index == 1)
  {
    if (head != NULL)
      temp->next = head;
    head = temp;
    return head;
  }
  int i = 1;
  int done = 0;
  node *current = head;
  node *prev;
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
    if (i == index - 1)
    {
      prev->next = temp;
      temp->next = current;
      done = 1;
      break;
    }
    i++;
  }
  if (!done)
  {
    printf("Index not valid!!\n");
  }
  return head;
}

node *deleteBegin(node *head)
{
  if (head == NULL)
  {
    printf("List in empty!\n");
    return head;
  }
  node *temp = head;
  head = head->next;
  free(temp);
  return head;
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

node *deleteIndex(node *head, int index)
{
  if (head == NULL)
  {
    printf("List is empty!!\n");
    return head;
  }
  if (index == 1)
  {
    node *temp = head->next;
    free(head);
    return temp;
  }
  int i = 1;
  int done = 0;
  node *current = head;
  node *prev;
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
    if (i == index - 1)
    {
      prev->next = current->next;
      free(current);
      done = 1;
      break;
    }
    i++;
  }
  if (!done)
  {
    printf("Index not valid!!\n");
  }
  return head;
}
