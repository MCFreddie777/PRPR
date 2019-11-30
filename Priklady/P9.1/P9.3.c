#include <stdio.h>

int deli(int n, int k)
{
  if (n % k == 0)
    return 1;
  if (k <= n-2 && deli(n, k+1))
    return 1;
  return 0;
}

int prvocislo(int n)
{
  return n == 2 || !deli(n, 2);
}

int main(void)
{
  int i, n;
  scanf("%d", &n);
  for (i = 2; i <= n; i++)
    if (prvocislo(i))
      printf("%d\n", i);
  return 0;
}
