#include <stdio.h>

int fakt(int n)
{
   return ((n <= 0) ? 1 : n * fakt(n - 1));
}

int main() 
{
   int i, f;

   printf("Zadajte cele cislo: ");
   scanf("%d", &i);
   printf("Faktorial %d je: %d\n", i, f = fakt(i));
return 0;
}

