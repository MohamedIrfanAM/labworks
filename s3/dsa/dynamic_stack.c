#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int top;
  int size;
  int *arr;
} stack;

stack *createStack();
void push(stack *s, int data);
void pop(stack *s);
void tos(stack *s);

int main()
{
  stack *s = createStack();
  int ch;
  do
  {
    printf("1)Push\n2)Pop\n3)tos\n4)Exit\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      printf("\n");
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
    else if (ch != 4)
    {
      printf("\nInvalid option!\n");
    }
  } while (ch != 4);
}

stack *createStack()
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->size = 1;
  s->top = -1;
  s->arr = (int *)calloc(1, sizeof(int));
  return s;
}

void push(stack *s, int data)
{
  if (s->top == s->size - 1)
  {
    int *a = (int *)calloc(s->size * 2, sizeof(int));
    for (int i = 0; i < s->size; i++)
    {
      a[i] = s->arr[i];
    }
    s->size *= 2;
    free(s->arr);
    s->arr = a;
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
