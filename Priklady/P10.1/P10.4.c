#include <stdio.h>
int dlzka_int(void)
{
  unsigned int x,
  i = 0;
  x = ~0;
  while ((x >>= 1) != 0)
    i++;
  return (++i);
}

int main(void)
{
  printf("Dlzka typu int je %d bitov\n", dlzka_int());

  return 0;
}


