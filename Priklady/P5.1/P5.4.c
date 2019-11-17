//P5.4
//Pozor pomocou operatora sizeof nevieme zistit velkost pola vo funkcii
//Smernik na pole nie je nositelom velkosti pola!!!!!
//Je nutny smernik na pole a dalsi parameter rozmer pola
  
#include <stdio.h>

void fn(int pole[])
{
  printf("%d\n", sizeof(pole)); // velkost pola x????
}

int main(void)
{
  int x[100], *p = &x[0];
  printf("%d %d\n", sizeof(x), sizeof(p)); // velkost pola, velkost smernika
  fn(x);		//volanie funkcie fn s parametrom statickeho pola
  return 0;
}
