//postupka
#include <stdio.h>
#include <stdlib.h>

char *postupka(char c, int n)
{
  char *str = malloc(n + 1);
  int i;
  for (i = 0; i < n; i++)
  {
    str[i] = c++;
    if (c == 'z' + 1)
      c = 'a';
    if (c == 'Z' + 1)
      c = 'A';
  }
  str[i] = 0;
  return str;
}

int main() {
  char znak, *retazec;
  int dlzka;
  printf("Zadaj zaciatok postupky a jej dlzku: ");
  scanf("%c %d", &znak, &dlzka);
  retazec = postupka(znak, dlzka);
  printf("\npostupka:%s\n", retazec);
  return 0;
}

