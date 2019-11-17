#include <stdio.h>
int main(void)
{
  int n, i, j;
  while (scanf("%d", &n) == 1)
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        if (i == 0 || j == 0 || i == n-1 || j == n-1 || i == j)
          putchar('#');
        else
          putchar(i > j ? '.' : ' ');
      printf("\n");
    }
  return 0;
}

