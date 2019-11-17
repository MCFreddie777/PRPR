//P7.10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char buf[50], **str;
  int n, i;
  scanf("%d", &n);
  str = malloc(n * sizeof(char*));
  for (i = 0; i < n; i++)
  {
    scanf("%s", buf, 50);
    str[i] = strdup(buf);
  }
  for (i = n - 1; i >= 0; i--)
    printf("%s\n", str[i]);
  return 0;
}
