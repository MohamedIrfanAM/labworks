#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int *arr, int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
}

void selectionSort(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
      }
    }
  }
}

void insersionSort(int *arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
      int t = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = t;
      j--;
    }
  }
}

void mergeSort(int *arr, int l, int r)
{
  if (l == r)
  {
    return;
  }
  int m = (l + r) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);

  int p = l;
  int q = m + 1;
  int *sorted = (int *)malloc(sizeof(int) * (r - l + 1));
  int k = 0;
  while (p <= m || q <= r)
  {
    if (p <= m && q <= r)
    {
      if (arr[p] < arr[q])
      {
        sorted[k] = arr[p];
        p++;
      }
      else
      {
        sorted[k] = arr[q];
        q++;
      }
    }
    else if (p <= m)
    {
      sorted[k] = arr[p];
      p++;
    }
    else if (q <= r)
    {
      sorted[k] = arr[q];
      q++;
    }
    k++;
  }
  for (int i = 0; i < k; i++)
  {
    arr[l + i] = sorted[i];
  }
  free(sorted);
}

void quickSort(int *arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int p = l;
  int k = l + 1;
  int s = r;
  while (arr[k] <= arr[p] && k <= r)
  {
    k++;
  }
  while (k <= s)
  {
    if (arr[k] <= arr[p])
    {
      k++;
      continue;
    }
    if (arr[s] <= arr[p])
    {
      int t = arr[k];
      arr[k] = arr[s];
      arr[s] = t;
      k++;
    }
    s--;
  }
  k--;
  int t = arr[k];
  arr[k] = arr[p];
  arr[p] = t;

  quickSort(arr, l, k - 1);
  quickSort(arr, k + 1, r);
}

void heapify(int arr[], int n, int loc)
{
  int largest = loc;
  int left = 2 * loc + 1;
  int right = 2 * loc + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != loc)
  {
    int t = arr[loc];
    arr[loc] = arr[largest];
    arr[largest] = t;

    heapify(arr, n, largest);
  }
}

void heapSort(int *arr, int n)
{
  for (int i = (n - 1) / 2; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    int t = arr[0];
    arr[0] = arr[i];
    arr[i] = t;
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[10] = {4, 5, 10, 3, 8, 2, 6, 7, 1, 9};
  heapSort(arr, 10);
  display(arr, 10);
}