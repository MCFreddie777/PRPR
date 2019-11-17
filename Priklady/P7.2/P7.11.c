#include <stdio.h>
#include <stdlib.h>

int nacitaj_pole(int **vysledok)
{
  int i = 0, n = 0, *pole = NULL, cislo;
  for (i = n = 0; scanf("%d", &cislo) == 1; i++)
  {
    if (i == n)
    {
      n = 2 * n + 1;
      pole = realloc(pole, n * sizeof(int));
    }
  pole[i] = cislo;
  }
  *vysledok = pole;
  return i;
}

int main(void)
{
  int i, pocet, *pole;
  pocet = nacitaj_pole(&pole);
  printf("Pocet cisel: %d\n", pocet);
  for (i = 0; i < pocet; i++)
    printf("%d\n", pole[i]);
  return 0;
}
