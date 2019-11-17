//P6.8
#include <stdio.h>

int najdi(char *s, char c)
{
  int i;
  for (i = 0; s[i]; i++)
    if (s[i] == c)
      return i;
  return -1;
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

