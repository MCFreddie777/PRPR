#include <stdio.h>

int ciferny_sucet(int x)
{
  if (x == 0)
    return 0;
  return x % 10 + ciferny_sucet(x / 10);
}

int main(void)
{
  int n, v;
  scanf("%d", &n);
  v = ciferny_sucet(n);
     printf("ciferny sucet cisla %d je %d \n", n, v);
  return 0;
}
