#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Instruction
{
  char label[10];
  char opcode[10];
  char operand[10];
} instruction;

instruction extractInstruction(char *line)
{
  instruction inst;
  int i = 0;
  int j = 0;
  if (line[0] != ' ')
  {
    while (line[i] != ' ')
    {
      inst.label[j] = line[i];
      i++;
      j++;
    }
  }
  inst.label[j] = '\0';
  while (line[i] == ' ')
  {
    i++;
  }
  j = 0;
  while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
  {
    inst.opcode[j] = line[i];
    i++;
    j++;
  }
  inst.opcode[j] = '\0';
  while (line[i] == ' ')
  {
    i++;
  }
  j = 0;
  while (line[i] != '\0' && line[i] != '\n')
  {
    inst.operand[j] = line[i];
    i++;
    j++;
  }
  inst.operand[j] = '\0';
  return inst;
}

char *fetchOpcode(char *opcode)
{
  FILE *optab;
  optab = fopen("optab.txt", "r");
  char line[100];
  char op[10];
  static char code[10];
  while (fgets(line, 100, optab) != NULL)
  {
    int i = 0;
    int j = 0;
    while (line[i] != ' ')
    {
      op[j] = line[i];
      i++;
      j++;
    }
    while (line[i] == ' ')
    {
      i++;
    }
    op[j] = '\0';
    j = 0;
    while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
    {
      code[j] = line[i];
      i++;
      j++;
    }
    code[j] = '\0';
    if (strcmp(op, opcode) == 0)
    {
      return code;
    }
  }
  return "";
}

int convetHex(char *hex)
{
  int dec = 0;
  int base = 1;
  int len = strlen(hex);
  for (int i = len - 1; i >= 0; i--)
  {
    if (hex[i] >= '0' && hex[i] <= '9')
    {
      dec += (hex[i] - 48) * base;
      base = base * 16;
    }
    else if (hex[i] >= 'A' && hex[i] <= 'F')
    {
      dec += (hex[i] - 55) * base;
      base = base * 16;
    }
  }
  return dec;
}

char *fetchSymbol(char *symbol)
{
  FILE *symtab;
  symtab = fopen("symtab.txt", "r");
  char line[100];
  char sym[10];
  static char addr[10];
  while (fgets(line, 100, symtab) != NULL)
  {
    int i = 0;
    int j = 0;
    while (line[i] != ' ')
    {
      sym[j] = line[i];
      i++;
      j++;
    }
    while (line[i] == ' ')
    {
      i++;
    }
    sym[j] = '\0';
    j = 0;
    while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
    {
      addr[j] = line[i];
      i++;
      j++;
    }
    addr[j] = '\0';
    if (strcmp(sym, symbol) == 0)
    {
      return addr;
    }
  }
  return "";
}

int main()
{
  FILE *symtab, *optab, *input, *output;

  input = fopen("addition.asm", "r");
  output = fopen("intermediate.txt", "w");
  symtab = fopen("symtab.txt", "w");
  optab = fopen("optab.txt", "r");

  char line[200];
  instruction inst;
  int LOCCTR = 0;
  int startAddress = 0;
  while (fgets(line, 200, input) != NULL)
  {
    inst = extractInstruction(line);
    if (strcmp(inst.opcode, "START") == 0)
    {
      LOCCTR = convetHex(inst.operand);
      startAddress = LOCCTR;
    }
    else if (fetchOpcode(inst.opcode) != "")
    {
      LOCCTR += 3;
    }
    else if (strcmp(inst.opcode, "WORD") == 0)
    {
      LOCCTR += 3;
    }
    else if (strcmp(inst.opcode, "RESW") == 0)
    {
      LOCCTR += 3 * atoi(inst.operand);
    }
    else if (strcmp(inst.opcode, "RESB") == 0)
    {
      LOCCTR += atoi(inst.operand);
    }
    else if (strcmp(inst.opcode, "BYTE") == 0)
    {
      LOCCTR += 1;
    }
    else if (strcmp(inst.opcode, "END") == 0)
    {
    }
    else
    {
      printf("Invalid opcode %s\n", inst.opcode);
      printf("Exiting...\n");
      exit(0);
    }

    if (strcmp(inst.label, "") != 0)
    {
      if (fetchSymbol(inst.label) != "")
      {
        printf("Duplicate symbol %s\n", inst.label);
        printf("Exiting...\n");
        exit(0);
      }
      else
      {
        fprintf(symtab, "%s %04X\n", inst.label, LOCCTR);
      }
    }
    // printf("%s %s %s\n", inst.label, inst.opcode, inst.operand);
    fprintf(output, "%04X %s %s %s\n", LOCCTR, inst.label, inst.opcode, inst.operand);
  }
  int programLength = LOCCTR - startAddress;
  fprintf(output, "%d\n", programLength);
}
