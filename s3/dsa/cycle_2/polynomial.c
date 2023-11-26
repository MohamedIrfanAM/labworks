#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int exp;
  int coeff;
  struct Node *next;
} node;

node *insertBegin(node *head, int coeff, int exp);
void display(node *head);
void bubblesort(node *head, int n);
node *multiply(node *a, node *b);
node *add(node *a, node *b);

int main()
{
  node *a = NULL;
  node *b = NULL;
  int n1, n2;
  printf("Enter the number of terms of a: ");
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++)
  {
    printf("\nEnter coefficient and exponents: ");
    int c, e;
    scanf("%d %d", &c, &e);
    a = insertBegin(a, c, e);
  }

  printf("\nEnter the number of terms of b: ");
  scanf("%d", &n2);
  for (int i = 0; i < n2; i++)
  {
    printf("\nEnter coefficient and exponents: ");
    int c, e;
    scanf("%d %d", &c, &e);
    b = insertBegin(b, c, e);
  }
  bubblesort(a, n1);
  bubblesort(b, n2);
  printf("a = ");
  display(a);
  printf("b = ");
  display(b);
  node *product = multiply(a, b);
  printf("Product = ");
  display(product);
  node *sum = add(a, b);
  printf("Sum = ");
  display(sum);
}

node *insertBegin(node *head, int coeff, int exp)
{
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
  {
    printf("Memory allocation failed");
    exit(0);
  }
  temp->coeff = coeff;
  temp->exp = exp;
  temp->next = head;
  head = temp;
  return head;
}

void bubblesort(node *head, int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    node *current = head;
    for (int j = 0; j < i; j++)
    {
      node *next = current->next;
      if (current->exp > next->exp)
      {
        int texp = current->exp;
        int tcoeff = current->coeff;
        current->coeff = next->coeff;
        current->exp = next->exp;
        next->coeff = tcoeff;
        next->exp = texp;
      }
      current = next;
    }
  }
}

void display(node *head)
{
  printf("\n");
  node *current = head;
  while (current != NULL)
  {
    if (current != head)
      printf(" + ");
    printf("%dx^%d", current->coeff, current->exp);
    current = current->next;
  }
  printf("\n");
}

node *multiply(node *a, node *b)
{
  node *result = NULL;
  node *currenta = a;
  int n = 0;
  while (currenta != NULL)
  {
    node *currentb = b;
    while (currentb != NULL)
    {
      int coeff = currenta->coeff * currentb->coeff;
      int exp = currenta->exp + currentb->exp;
      node *currentr = result;
      int alreadyExist = 0;
      while (currentr != NULL)
      {
        if (currentr->exp == exp)
        {
          currentr->coeff += coeff;
          alreadyExist = 1;
        }
        currentr = currentr->next;
      }
      if (!alreadyExist)
      {
        n++;
        result = insertBegin(result, coeff, exp);
      }
      currentb = currentb->next;
    }
    currenta = currenta->next;
  }
  bubblesort(result, n);
  return result;
}

node *add(node *a, node *b)
{
  node *result = NULL;
  node *currenta = a;
  node *currentb = b;
  int n = 0;
  while (currenta != NULL || currentb != NULL)
  {
    if (currenta != NULL && currentb != NULL)
    {
      if (currenta->exp == currentb->exp)
      {
        int coeff = currenta->coeff + currentb->coeff;
        result = insertBegin(result, coeff, currenta->exp);
        n += 1;
      }
      else
      {
        result = insertBegin(result, currenta->coeff, currenta->exp);
        result = insertBegin(result, currentb->coeff, currentb->exp);
        n += 2;
      }
      currenta = currenta->next;
      currentb = currentb->next;
    }
    else if (currenta != NULL)
    {
      result = insertBegin(result, currenta->coeff, currenta->exp);
      currenta = currenta->next;
      n++;
    }
    else if (currentb != NULL)
    {
      result = insertBegin(result, currentb->coeff, currentb->exp);
      currentb = currentb->next;
      n++;
    }
  }
  bubblesort(result, n);
  return result;
}