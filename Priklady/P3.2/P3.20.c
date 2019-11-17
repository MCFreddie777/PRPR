#include<stdio.h>

void vymen(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}
int main(void)
{
  int i = 5, j = 10;
  printf("%d %d\n", i, j); // 5 10
  vymen(&i, &j);
  printf("%d %d\n", i, j); // 10 5
  return 0;
}

