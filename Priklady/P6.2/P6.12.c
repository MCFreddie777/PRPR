//P6.12
//Vytvaranie pola vo funkcii main, jeho uprava vo funkcii
//Upravene pole "vratime" pomocou smernika na smernik
//Pomocou návratovej hodnoty "vratime" pocet parnych cisel
#include <stdio.h>
#include <stdlib.h>

int najdi_parne(int *a, int n, int **vysledok)
{
  int i, m, *pole;
  for (m = i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      m++;
   pole = malloc(m * sizeof(int));
   for (m = i = 0; i < n; i++)
     if (a[i] % 2 == 0)
       pole[m++] = a[i];
   *vysledok = pole;
   return m;
}

int main(void)
{
   int i, n, *p, x[] = { 1, 2, 3, 8, 5, 6, 7, 4, 9, 10 };
   n = najdi_parne(x, 10, &p);
   for (i = 0; i < n; i++)
     printf("%d ", p[i]); // 2 8 6 4 10
   return 0;
}
