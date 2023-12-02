#include <stdlib.h>
#include <stdio.h>

#define MAX_TERMS 101

typedef struct term
{
  int row, col, value;
} term;

term termsa[MAX_TERMS];
term termsb[MAX_TERMS];

void convert(int m, int n, int a[m][n], term terms[]);
void display(term terms[]);
void transpose(term terms[]);
void add(term termsa[], term termsb[]);

int main()
{
  int ch;
  printf("Enter order of matrix a: ");
  int m, n, p, q;
  scanf("%d %d", &m, &n);
  int a[m][n];
  printf("\nEnter matrix a:\n");
  for (int i = 0; i < m; i++)
  {
    printf("Enter row %d: ", i + 1);
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  printf("\nEnter order of matrix b: ");
  scanf("%d %d", &p, &q);
  int b[p][q];
  printf("\nEnter matrix b:\n");
  for (int i = 0; i < p; i++)
  {
    printf("Enter row %d: ", i + 1);
    for (int j = 0; j < q; j++)
    {
      scanf("%d", &b[i][j]);
    }
  }
  convert(m, n, a, termsa);
  convert(p, q, b, termsb);
  printf("\nMatrix A = \n");
  display(termsa);
  printf("\nMatrix B = \n");
  display(termsb);
  add(termsa, termsb);
}

void convert(int m, int n, int a[m][n], term terms[])
{
  int i, j, k = 1;
  terms[0].row = m;
  terms[0].col = n;
  terms[0].value = 0;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (a[i][j] != 0)
      {
        terms[k].row = i + 1;
        terms[k].col = j + 1;
        terms[k].value = a[i][j];
        k++;
      }
    }
  }
  terms[0].value = k - 1;
}

void display(term terms[])
{
  printf("\nRow\tColumn\tValue\n");
  for (int i = 0; i <= terms[0].value; i++)
  {
    printf("%d\t%d\t%d\n", terms[i].row, terms[i].col, terms[i].value);
  }
}

void transpose(term terms[])
{
  term transposed[terms[0].value];
  transposed[0].row = terms[0].col;
  transposed[0].col = terms[0].row;
  transposed[0].value = terms[0].value;
  for (int k = 1; k <= terms[0].col; k++)
  {
    for (int i = 1; i <= terms[0].value; i++)
    {
      if (terms[i].col == k)
      {
        transposed[i].col = terms[i].row;
        transposed[i].row = k;
        transposed[i].value = terms[i].value;
      }
    }
  }
  display(transposed);
}

void add(term termsa[], term termsb[])
{
  term sum[MAX_TERMS];
  sum[0].row = termsa[0].row;
  sum[0].col = termsa[0].col;
  sum[0].value = 0;
  int i = 1, j = 1, k = 1;
  while (i <= termsa[0].value || j <= termsb[0].value)
  {
    if (i <= termsa[0].value)
    {
      if (j <= termsb[0].value)
      {
        if (termsa[i].row == termsb[j].row)
        {
          if (termsa[i].col == termsb[j].col)
          {
            sum[k].row = termsa[i].row;
            sum[k].col = termsa[i].col;
            sum[k].value = termsa[i].value + termsb[j].value;
            i++;
            j++;
          }
          else if (termsa[i].col < termsb[j].col)
          {
            sum[k].row = termsa[i].row;
            sum[k].col = termsa[i].col;
            sum[k].value = termsa[i].value;
            i++;
          }
          else
          {
            sum[k].row = termsb[j].row;
            sum[k].col = termsb[j].col;
            sum[k].value = termsb[j].value;
            j++;
          }
        }
        else if (termsa[i].row < termsb[j].row)
        {
          sum[k].row = termsa[i].row;
          sum[k].col = termsa[i].col;
          sum[k].value = termsa[i].value;
          i++;
        }
        else
        {
          sum[k].row = termsb[j].row;
          sum[k].col = termsb[j].col;
          sum[k].value = termsb[j].value;
          j++;
        }
      }
    }
    else
    {
      sum[k].row = termsb[j].row;
      sum[k].col = termsb[j].col;
      sum[k].value = termsb[j].value;
      j++;
    }
    k++;
  }
  sum[0].value = k - 1;
  printf("\nSum:\n");
  display(sum);

  printf("\nTraspose A = :\n");
  transpose(termsa);
  printf("\nTraspose B = :\n");
  transpose(termsb);
}