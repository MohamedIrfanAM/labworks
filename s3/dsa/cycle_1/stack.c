#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int top;
  int size;
  int arr[100];
} stack;

stack *createStack();
void push(stack *s, int data);
void pop(stack *s);
void tos(stack *s);
void display(stack *s);

int main()
{
  stack *s = createStack();
  s->size = 100;
  s->top = -1;
  int ch;
  printf("1)Push\n2)Pop\n3)tos\n4)Display\n5)Exit\n");
  do
  {
    printf("Choice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      push(s, x);
    }
    else if (ch == 2)
    {
      pop(s);
    }
    else if (ch == 3)
    {
      tos(s);
    }
    else if (ch == 4)
    {
      display(s);
    }
    else if (ch != 5)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 5);
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
  if (s->top == s->size - 1)
  {
    printf("Stack Overflow\n");
    return;
  }
  s->top++;
  s->arr[s->top] = data;
}

void pop(stack *s)
{
  if (s->top < 0)
  {
    printf("Stack underflow\n");
    return;
  }
  printf("\nRemoved element = %d\n", s->arr[s->top]);
  s->top--;
}

void tos(stack *s)
{
  if (s->top < 0)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("\nTOS = %d\n", s->arr[s->top]);
}

void display(stack *s)
{
  printf("\n");
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d ", s->arr[i]);
  }
  printf("\n");
}