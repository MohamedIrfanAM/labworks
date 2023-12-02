#include <stdlib.h>
#include <stdio.h>

typedef struct Term
{
  int exp;
  int coeff;
} term;

typedef struct polynomial
{
  term *terms;
  int length;
  int size;
} polynomial;

polynomial *createPolynomial(int size);
void insertTerm(polynomial *p, int coeff, int exp);
void display(polynomial *p);
void bubblesort(term *arr, int size);
polynomial *add(polynomial *p, polynomial *q);

int main()
{
  polynomial *a = NULL;
  polynomial *b = NULL;
  int n1, n2;
  printf("Enter the number of terms of a: ");
  scanf("%d", &n1);
  a = createPolynomial(n1);
  for (int i = 0; i < n1; i++)
  {
    printf("\nEnter coefficient and exponents: ");
    int c, e;
    scanf("%d %d", &c, &e);
    insertTerm(a, c, e);
  }

  printf("\nEnter the number of terms of b: ");
  scanf("%d", &n2);
  b = createPolynomial(n2);
  for (int i = 0; i < n2; i++)
  {
    printf("\nEnter coefficient and exponents: ");
    int c, e;
    scanf("%d %d", &c, &e);
    insertTerm(b, c, e);
  }
  bubblesort(a->terms, n1);
  bubblesort(b->terms, n2);
  printf("a = ");
  display(a);
  printf("b = ");
  display(b);
  polynomial *sum = add(a, b);
  printf("Sum = ");
  display(sum);
  free(a);
  free(b);
  free(sum);
}

polynomial *createPolynomial(int size)
{
  polynomial *p = (polynomial *)malloc(sizeof(polynomial));
  p->terms = (term *)malloc(size * sizeof(term));
  p->size = size;
  p->length = 0;
  return p;
}

void insertTerm(polynomial *p, int coeff, int exp)
{
  if (p->length == p->size)
  {
    printf("\nPolynomial size exceeded!");
  }
  p->terms[p->length].coeff = coeff;
  p->terms[p->length].exp = exp;
  p->length++;
}

void bubblesort(term *arr, int size)
{
  for (int i = size - 1; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j].exp > arr[j + 1].exp)
      {
        int texp = arr[j].exp;
        int tcoeff = arr[j].coeff;
        arr[j].coeff = arr[j + 1].coeff;
        arr[j].exp = arr[j + 1].exp;
        arr[j + 1].coeff = tcoeff;
        arr[j + 1].exp = texp;
      }
    }
  }
}

void display(polynomial *p)
{
  for (int i = 0; i < p->length; i++)
  {
    if (i != 0)
      printf(" + ");
    printf("%dx^%d", p->terms[i].coeff, p->terms[i].exp);
  }
  printf("\n");
}

polynomial *add(polynomial *p, polynomial *q)
{
  term *result = createPolynomial(p->size + q->size);
  int i = 0, j = 0;
  while (i < p->length || j < q->length)
  {
    if (i >= p->length)
    {
      insertTerm(result, q->terms[j].coeff, q->terms[j].exp);
      j++;
      continue;
    }
    if (j >= q->length)
    {
      insertTerm(result, p->terms[i].coeff, p->terms[i].exp);
      i++;
      continue;
    }
    if (p->terms[i].exp < q->terms[j].exp)
    {
      insertTerm(result, p->terms[i].coeff, p->terms[i].exp);
      i++;
    }
    else if (p->terms[i].exp > q->terms[j].exp)
    {
      insertTerm(result, q->terms[j].coeff, q->terms[j].exp);
      j++;
    }
    else
    {
      insertTerm(result, p->terms[i].coeff + q->terms[j].coeff, p->terms[i].exp);
      i++;
      j++;
    }
  }
  return result;
}