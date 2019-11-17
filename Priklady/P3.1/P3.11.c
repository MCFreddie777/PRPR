#include<stdio.h>
void nastav(int x)
{
  x = 10;
}
int main(void)
{
  int i = 3;
  printf("Povodna hodnota: %d\n", i); // 3
  nastav(i);
  printf("Upravena hodnota: %d\n", i); // 3
  return 0;
}

