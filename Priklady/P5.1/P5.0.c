#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, *x, *y;
  x = calloc(100, sizeof(int));
  y = malloc(100 * sizeof(int));
  for (i = 0; i < 3; i++)
  printf("x[%d]=%d y[%d]=%d\n", i, x[i], i, y[i]);
  return 0;
}
