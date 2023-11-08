#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
  int id;
  char name[100];
  int salary;
} employee;

int main()
{
  printf("Enter the number of employees: ");
  int n;
  scanf("%d", &n);
  employee *arr = (employee *)malloc(n * sizeof(employee));
  for (int i = 0; i < n; i++)
  {
    printf("\nEnter the id, name and salary of employee %d: ", i + 1);
    scanf("%d %s %d", &arr[i].id, arr[i].name, &arr[i].salary);
  }
  printf("\nEnter the id of the employee to search: ");
  int id;
  scanf("%d", &id);
  for (int i = 0; i < n; i++)
  {
    if (arr[i].id == id)
    {
      printf("\nEmployee found\n");
      printf("Id: %d\nName: %s\nSalary: %d\n", arr[i].id, arr[i].name, arr[i].salary);
      return 0;
    }
  }
  printf("\nEmployee not found\n");
}