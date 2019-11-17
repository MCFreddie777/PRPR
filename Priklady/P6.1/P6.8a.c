//P6.8a
//Poziciu pocitame od 0
//Rekurzivna funkcia
#include <stdio.h>

int najdi(char *s, char c)
{
  int i;
  if (*s == 0)
    return -1;
  if (*s == c)
    return 0;
  if ((i = najdi(s+1, c)) < 0)
    return -1;
  return i + 1;
}


int main(void)
{
  char buf[1000], znak[2];
  int pos;
  scanf("%s %s", buf, znak);
  if ((pos = najdi(buf, *znak)) >= 0)
    printf("Znak %c je na pozicii %d v %s\n", *znak, pos, buf);
  else
    printf("Znak %c sa v %s nenachadza\n", *znak, buf);
return 0;
}
