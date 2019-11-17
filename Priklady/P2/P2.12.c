//pozor chybna podmienka
#include <stdio.h>

int main(void)
{
  int i, k;
  scanf("%d", &k);
  while (scanf("%d", &i) == 1)
    if (i % k == 0)
      printf("%d\n", i);
  return 0;
}

