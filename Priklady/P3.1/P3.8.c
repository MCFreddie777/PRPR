#include <stdio.h>
void nekonecno()
{
  printf("Nikdy neskoncim!?\n");
  nekonecno();
}
int main(void)
{
  nekonecno(0);
  return 0;
}
