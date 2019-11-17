#include <stdio.h>
#include <stdlib.h>
void hadik(char **a, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      if (i % 2 == 0)
        a[i][j] = 'a' + (n*i+j) % 26 ;
      else
        a[i][j] = 'a' + (n*i+n-j-1) % 26 ;
     }
}

int main(void)
{
  int i, j, n;
  char **a;
  while ( scanf("%d", &n) == 1 )
  {
    a = malloc(sizeof(char*)*n) ;
    for (i = 0; i < n; i++)
      a[i] = malloc(n) ;
    hadik(a, n);
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        printf("%c", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}


