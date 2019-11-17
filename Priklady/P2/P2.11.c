#include <stdio.h>
int main(void)
{
int i, j = 0 ;
  while (scanf("%d", &i ) == 1 )
    j += 1-(i%2) ;
  printf("%d\n", j );
return 0;
}
