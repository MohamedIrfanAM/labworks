#include <stdio.h>
#include <stdlib.h>

typedef struct Block
{
  int size;
  int isOccupied;
  struct Block *next;
  struct Block *prev;
} block;

typedef struct Memory
{
  int totalSize;
  int freeSize;
  block *head;
  block *tail;
} memory;

memory *initializeMemory(int *sizes, int length);
void displayMemory(memory *m);
void garbageCollect(memory *m);
void firstFit(memory *m, int size);
void bestFit(memory *m, int size);
void worstFit(memory *m, int size);
void freeMemory(memory *m, int index);

int main()
{
  int sizes[10] = {1, 2, 3, 4, 5, 6, 8, 7, 9, 10};
  memory *m = initializeMemory(sizes, 10);
  displayMemory(m);
  worstFit(m, 7);
  // garbageCollect(m);
  displayMemory(m);
  freeMemory(m, 0);
  displayMemory(m);
}

memory *initializeMemory(int *sizes, int length)
{
  memory *m = (memory *)malloc(sizeof(memory));
  // initialize first block
  block *head = (block *)malloc(sizeof(block));
  head->size = sizes[0];
  head->isOccupied = 0;
  head->next = NULL;
  head->prev = NULL;
  m->head = head;
  m->tail = head;
  m->totalSize = sizes[0];
  m->freeSize = sizes[0];
  block *prev = head;
  // initialize rest of the blocks
  for (int i = 1; i < length; i++)
  {
    block *new = (block *)malloc(sizeof(block));
    new->size = sizes[i];
    new->isOccupied = 0;
    new->next = NULL;
    new->prev = prev;
    prev->next = new;
    prev = new;
    m->tail = new;
    m->totalSize += sizes[i];
    m->freeSize += sizes[i];
  }
  return m;
}

void displayMemory(memory *m)
{
  printf("Total Size = %d, Free size = %d\n", m->totalSize, m->freeSize);
  block *current = m->head;
  int i = 0;
  while (current != NULL)
  {
    if (current->isOccupied)
    {
      printf("P-%d\t", i);
      i++;
    }
    else
    {
      printf("free\t");
    }
    current = current->next;
  }
  printf("\n");
  current = m->head;
  while (current != NULL)
  {
    printf("%dkb\t", current->size);
    current = current->next;
  }
  printf("\n");
}

void garbageCollect(memory *m)
{
  block *current = m->head;
  while (current != NULL)
  {
    block *next = current->next;
    m->tail = current;
    if (current->prev != NULL && !current->prev->isOccupied && !current->isOccupied)
    {
      current->prev->size += current->size;
      current->prev->next = current->next;
      if (current->next != NULL)
      {
        current->next->prev = current->prev;
      }
      m->tail = current->prev;
      free(current);
    }
    current = next;
  }
}

void firstFit(memory *m, int size)
{
  block *current = m->head;
  while (current != NULL)
  {
    if (!current->isOccupied && current->size >= size)
    {
      current->isOccupied = 1;
      m->freeSize -= size;
      if (current->size == size)
      {
        return;
      }
      block *new = (block *)malloc(sizeof(block));
      new->isOccupied = 0;
      new->size = current->size - size;
      new->prev = current;
      new->next = current->next;
      if (current->next != NULL)
      {
        current->next->prev = new;
      }
      current->size = size;
      current->next = new;
      if (current == m->tail)
      {
        m->tail = new;
      }
      return;
    }
    current = current->next;
  }
  printf("Required block is not currently avilable!\n");
}

void bestFit(memory *m, int size)
{
  block *current = m->head;
  block *best = NULL;
  while (current != NULL)
  {
    if (!current->isOccupied && current->size >= size)
    {
      if (best == NULL || best->size > current->size)
      {
        best = current;
      }
    }
    current = current->next;
  }
  if (best == NULL)
  {
    printf("Required block is not currently avilable!\n");
    return;
  }
  best->isOccupied = 1;
  m->freeSize -= size;
  if (best->size == size)
  {
    return;
  }
  block *new = (block *)malloc(sizeof(block));
  new->isOccupied = 0;
  new->size = best->size - size;
  new->prev = best;
  new->next = best->next;
  if (best->next != NULL)
  {
    best->next->prev = new;
  }
  best->size = size;
  best->next = new;
  if (best == m->tail)
  {
    m->tail = new;
  }
}

void worstFit(memory *m, int size)
{
  block *current = m->head;
  block *worst = NULL;
  while (current != NULL)
  {
    if (!current->isOccupied && current->size >= size)
    {
      if (worst == NULL || worst->size < current->size)
      {
        worst = current;
      }
    }
    current = current->next;
  }
  if (worst == NULL)
  {
    printf("Required block is not currently avilable!\n");
    return;
  }
  worst->isOccupied = 1;
  m->freeSize -= size;
  if (worst->size == size)
  {
    return;
  }
  block *new = (block *)malloc(sizeof(block));
  new->isOccupied = 0;
  new->size = worst->size - size;
  new->prev = worst;
  new->next = worst->next;
  if (worst->next != NULL)
  {
    worst->next->prev = new;
  }
  worst->size = size;
  worst->next = new;
  if (worst == m->tail)
  {
    m->tail = new;
  }
}

void freeMemory(memory *m, int index)
{
  block *current = m->head;
  int i = 0;
  while (current != NULL)
  {
    if (current->isOccupied)
    {
      if (i == index)
      {
        m->freeSize += current->size;
        current->isOccupied = 0;
        return;
      }
      i++;
    }
    current = current->next;
  }
  printf("Block with specified index not found!!");
}