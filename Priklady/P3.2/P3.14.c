#include <stdio.h>

long reverzne_cislo(long x)
{
  long y = 0;
  while (x > 0)
  {
    y = 10*y + (x % 10);
    x /= 10;
  }
  return y;
}

int main()
{
  long x, rev;
  while (scanf("%ld", &x) > 0)
  {
    rev = reverzne_cislo(x);
    printf("%ld\n", rev);
    if (rev == x)
      printf("Cislo %ld je palindrom\n", x);
    else
      printf("Cislo %ld nie je palindrom\n", x);
  }
  return 0;
}

