#include <stdio.h>

int otoc(int x, int otocene)
{
  if (x == 0)
    return otocene;
  return otoc(x / 10, 10 * otocene + (x % 10));
}

int main(void)
{
  int n, otocene;
  scanf("%d", &n);
  otocene = otoc(n, otocene);
  printf("povodne cislo %d, otocene %d\n", n, otocene);
  return 0;
}

