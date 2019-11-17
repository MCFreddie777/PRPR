//pozor chybna podmienka opravena
#include <stdio.h>

int main(void)
{
  int i, k;
  scanf("%d", &k);
  while (scanf("%d", &i) == 1)
    if (k != 0 && i % k == 0)
      printf("%d\n", i);
  return 0;
}

