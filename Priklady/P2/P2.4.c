#include <stdio.h>
int main(void)
{
  int i = 15, j = 5;

  if ((i %= j)==0 || ++j)  
  printf("i = %d  j = %d\n", i, j);
  else
  printf("i = %d  j = %d\n", i+1, j+1);
return 0;
}

