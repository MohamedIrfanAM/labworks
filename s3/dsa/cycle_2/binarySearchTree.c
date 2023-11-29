#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} node;

// Binary Tree
node *insert(node *root, int data);
void search(node *root, int key);
node *delete(node *root, int key);

int main()
{
  node *root = NULL;

  int ch;
  do
  {
    printf("\n1)Insert Node\n2)Search Node\n3)Delete Node\n5)Exit\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      int x;
      printf("\nEnter the data: ");
      scanf("%d", &x);
      root = insert(root, x);
    }
    else if (ch == 2)
    {
      int x;
      printf("\nEnter the key to search: ");
      scanf("%d", &x);
      search(root, x);
    }
    if (ch == 3)
    {
      int x;
      printf("\nEnter the key to delete: ");
      scanf("%d", &x);
      root = delete (root, x);
    }
  } while (ch != 4);
}

node *insert(node *root, int data)
{
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  if (root == NULL)
  {
    root = new;
    return root;
  }
  node *ptr = root;
  node *prev = root;
  while (ptr != NULL)
  {
    prev = ptr;
    if (data > ptr->data)
    {
      ptr = ptr->right;
    }
    else if (data < ptr->data)
    {
      ptr = ptr->left;
    }
    else
    {
      printf("\nNode already exist!!\n");
      return root;
    }
  }
  if (data > prev->data)
  {
    prev->right = new;
  }
  else
  {
    prev->left = new;
  }
  return root;
}

node *inorderSuccessor(node *n)
{
  node *current;
  node *prev;
  if (n->right == NULL || n->left == NULL)
  {
    printf("\nNode is empty to find null pointer!!\n");
    return n;
  }
  current = n;
  prev = n;
  current = current->right;
  while (current != NULL)
  {
    prev = current;
    current = current->left;
  }
  return prev;
}

node *delete(node *root, int key)
{
  node *current = root;
  node *prev = NULL;
  while (current != NULL)
  {
    prev = current;
    if (current->data == key)
    {
      if (current->left != NULL && current->right != NULL)
      {
        node *successor = inorderSuccessor(current);
        // printf("\nInorder successor = %d", successor->data);
        current->data = successor->data;
        free(successor);
      }
      else
      {
        node *child = current->left;
        if (current->right != NULL)
        {
          child = current->right;
        }
        if (current == root)
        {
          root = child;
        }
        else if (prev->left == current)
        {
          prev->left = child;
        }
        else
        {
          prev->right = child;
        }
        free(current);
      }
      printf("\nItem deleted successfully!!\n");
      return root;
    }
    else if (current->data < key)
    {
      current = current->right;
    }
    else
    {
      current = current->left;
    }
  }
  printf("\nItem not found!!\n");
  return root;
}

void search(node *root, int key)
{
  node *current = root;
  printf("\nSearching - ");
  while (current != NULL)
  {
    printf(" %d ", current->data);
    if (current->data == key)
    {
      printf("\nItem found!\n");
      return;
    }
    else if (current->data < key)
    {
      current = current->right;
    }
    else
    {
      current = current->left;
    }
  }
  printf("\nItem not found!!\n");
}
