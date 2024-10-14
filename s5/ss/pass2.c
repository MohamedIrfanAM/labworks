#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record
{
  char address[10];
  char label[10];
  char opcode[10];
  char operand[10];
  char objectCode[10];
} record;

char *fetchSymbol(char *symbol)
{
  FILE *symtab;
  symtab = fopen("symtab.txt", "r");
  char line[100];
  char sym[10];
  char *addr = malloc(10 * sizeof(char));
  while (fscanf(symtab, "%s %s", sym, addr) != EOF)
  {
    if (strcmp(sym, symbol) == 0)
    {
      fclose(symtab);
      return addr;
    }
  }
  return "";
}

char *fetchOpcode(char *opcode)
{
  FILE *optab;
  optab = fopen("optab.txt", "r");
  char line[100];
  char op[10];
  char *code = malloc(10 * sizeof(char));
  while (fscanf(optab, "%s %s", op, code) != EOF)
  {
    if (strcmp(op, opcode) == 0)
    {
      fclose(optab);
      return code;
    }
  }
  fclose(optab);
  return "";
}

int main()
{
  FILE *symtab, *optab, *input, *output, *length, *listing;

  input = fopen("intermediate.txt", "r");
  listing = fopen("listing.txt", "w");
  output = fopen("objectcode", "w");
  length = fopen("length.txt", "r");

  char line[100];
  record rec;

  char programSize[10];
  char programLength[10];
  fscanf(length, "%s %s", programSize, programLength);

  while (fscanf(input, "%s %s %s %s", rec.address, rec.label, rec.opcode, rec.operand) != EOF)
  {
    printf("%s\n", rec.opcode);
    if (strcmp(rec.opcode, "START") == 0)
    {
      fprintf(listing, "%s %s %s %s -\n", rec.address, rec.label, rec.opcode, rec.operand);
      fprintf(output, "H^%s^00%s^%s\n", rec.label, rec.address, programLength);
      fprintf(output, "T^00%s^%s", rec.address, programSize);
      continue;
    }
    else if (strcmp(rec.opcode, "END") == 0)
    {
      fprintf(listing, "%s %s %s %s -\n", rec.address, rec.label, rec.opcode, rec.operand);
      fprintf(output, "\nE^00%s\n", rec.operand);
      break;
    }
    else if (strcmp(rec.opcode, "RESW") == 0 || strcmp(rec.opcode, "RESB") == 0)
    {
      fprintf(listing, "%s %s %s %s -\n", rec.address, rec.label, rec.opcode, rec.operand);
    }
    else if (strcmp(rec.opcode, "WORD") == 0)
    {
      fprintf(listing, "%s %s %s %s %06X\n", rec.address, rec.label, rec.opcode, rec.operand, rec.operand);
      fprintf(output, " %06X", atoi(rec.operand));
    }
    else if (strcmp(rec.opcode, "BYTE") == 0)
    {
      fprintf(listing, "%s %s %s %s %02X\n", rec.address, rec.label, rec.opcode, rec.operand, rec.operand);
      fprintf(output, " %02X", atoi(rec.operand));
    }
    else
    {
      char *opcode = fetchOpcode(rec.opcode);
      char *symbol = fetchSymbol(rec.operand);
      if (strcmp(opcode, "") == 0)
      {
        printf("Invalid opcode %s\n", rec.opcode);
        return 1;
      }
      if (strcmp(symbol, "") == 0)
      {
        printf("Undefined symbol %s\n", rec.operand);
        return 1;
      }
      printf("%s %s %s %s %s%s\n", rec.address, rec.label, rec.opcode, rec.operand, opcode, symbol);
      fprintf(listing, "%s %s %s %s %s%s\n", rec.address, rec.label, rec.opcode, rec.operand, opcode, symbol);
      fprintf(output, " %s^%s", opcode, symbol);
    }
  }
}
