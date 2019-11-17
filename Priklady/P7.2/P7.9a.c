//P7.9a
#include <stdio.h>
#include <stdlib.h>

int *najdi_parne(int *a, int n, int *m)
{
  int i, *pole;
  for (*m = i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      (*m)++;
  pole = malloc(*m * sizeof(int));
  for (*m = i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      pole[(*m)++] = a[i];
  return pole;
}
int main(void)
{
  int i, velkost, *p, x[] = { 1, 2, 3, 8, 5, 6, 7, 4, 9, 10 };
  p = najdi_parne(x, 10, &velkost);
  printf("%d\n", velkost);
  for (i = 0; i < velkost; i++)
    printf("%d ", p[i]); // 2 8 6 4 10
  return 0;
}

