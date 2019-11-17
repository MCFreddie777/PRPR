#include <stdio.h>

int main() 
{ 
   int i, j;

   scanf("%d %d", &i, &j);
   printf("i: %d, j: %d\n", i, j);
   j = j + 2 * i;
   printf("j: %d\n", j);

   return 0;
}

