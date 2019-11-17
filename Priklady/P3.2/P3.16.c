#include<stdio.h>
void nastav(int *x)
{
  *x = 4;
}
int main(void)
{
  int i = 3;
  printf("Povodna hodnota: %d\n", i); 
  nastav(&i);
  printf("Upravena hodnota: %d\n", i); 
  return 0;
}
