#include <stdio.h>
int main()
{
  char c1, c2, *p_c = &c1;
  while((c1=fgetc(stdin)) != '*')
  {
    c2 = *p_c;
    printf("c1: %c (%x), c2: %c (%x), p_c: %c (%x)\n", c1, &c1, c2, &c2, *p_c,   p_c);
  }
  return 0;
}

