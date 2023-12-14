#include <stdio.h>
#include <stdlib.h>

typedef struct NodeClosed
{
  int key;
  int value;
  struct NodeClosed *next;
} nodeClose;

typedef struct NodeOpen
{
  int key;
  int value;
} nodeOpen;

typedef struct Hashclosed
{
  int size;
  nodeClose **table;
} hashClosed;

typedef struct Hashopen
{
  int size;
  nodeOpen *table;
} hashOpen;

hashClosed *createHashClosed(int size)
{
  hashClosed *h = (hashClosed *)malloc(sizeof(hashClosed));
  h->size = size;
  h->table = (nodeClose **)malloc(sizeof(nodeClose *) * size);
  for (int i = 0; i < size; i++)
  {
    h->table[i] = NULL;
  }
  return h;
}

hashOpen *createHashOpen(int size)
{
  hashOpen *h = (hashOpen *)malloc(sizeof(hashOpen));
  h->size = size;
  h->table = (nodeOpen *)malloc(sizeof(nodeOpen) * size);
  for (int i = 0; i < size; i++)
  {
    h->table[i].key = -1;
  }
  return h;
}

void hashOpenInsert(hashOpen *h, int key, int value)
{
  int hash = key % h->size;
  printf("Inserting at hash = %d\n", hash);
  if (h->table[hash].key == -1)
  {
    h->table[hash].key = key;
    h->table[hash].value = value;
    return;
  }
  int i = 1;
  while (h->table[hash].key != -1)
  {
    hash = (key + i) % h->size;
    i++;
  }
  h->table[hash].key = key;
  h->table[hash].value = value;
}

int hashOpenGet(hashOpen *h, int key)
{
  int hash = key % h->size;
  int i = 0;
  int found = 0;
  while (i < h->size)
  {
    hash = (key + i) % h->size;
    if (h->table[hash].key == key)
    {
      found = 1;
      return h->table[hash].value;
    }
    i++;
  }
  if (!found)
  {
    printf("Key not found!!\n");
    return -1;
  }
}

void hashClosedInsert(hashClosed *h, int key, int value)
{
  int hash = key % h->size;
  nodeClose *new = (nodeClose *)malloc(sizeof(nodeClose));
  new->key = key;
  new->value = value;
  new->next = NULL;

  printf("Inserting at hash = %d\n", hash);

  if (h->table[hash] == NULL)
  {
    h->table[hash] = new;
    return;
  }
  nodeClose *current = h->table[hash];
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = new;
}

int hashClosedGet(hashClosed *h, int key)
{
  int hash = key % h->size;
  nodeClose *current = h->table[hash];
  int found = 0;
  while (current != NULL)
  {
    if (key == current->key)
    {
      found = 1;
      return current->value;
    }

    current = current->next;
  }
  if (!found)
  {
    printf("Key not found!!\n");
    return -1;
  }
}

int main()
{
  hashClosed *hashclosed = createHashClosed(10);
  hashClosedInsert(hashclosed, 11, 8);
  hashClosedInsert(hashclosed, 21, 10);
  hashClosedInsert(hashclosed, 12, 9);
  printf("key = %d, value = %d\n", 11, hashClosedGet(hashclosed, 11));
  printf("key = %d, value = %d\n", 21, hashClosedGet(hashclosed, 21));

  hashOpen *hashopen = createHashOpen(10);
  hashOpenInsert(hashopen, 23, 90);
  hashOpenInsert(hashopen, 43, 100);
  hashOpenInsert(hashopen, 20, 75);
  printf("key = %d, value = %d\n", 23, hashOpenGet(hashopen, 23));
  printf("key = %d, value = %d\n", 43, hashOpenGet(hashopen, 43));
  printf("key = %d, value = %d\n", 20, hashOpenGet(hashopen, 20));
}