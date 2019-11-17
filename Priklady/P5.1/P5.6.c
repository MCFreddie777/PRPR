#include <stdio.h>
#include <stdlib.h>
#define N 5

int *alokuj(int n)
{
  return ((int *) malloc(n * sizeof(int)));
}

void nacitaj(int *p, int n)
{ 
  int i;
  for(i = 0; i < n; i++) {
    printf("Zadajte %d-te cislo: ", i+1);
    scanf("%d", p + i);
  }
}

int maximum(int pole[], int n) 
{
    int *p_max  = pole, *p;
    for (p = pole + 1; p < pole + n; p++) {
        if (*p > *p_max)
            p_max = p;
    }
    return (*p_max);
}

int najcastejsi( int *a , int n)
{
  int i, j, k, pocet=0, vysledok ;
  for (i = 0; i < n ; i++)  {
    for (j = k = 0; j < n; j++)
     if ( a[j] == a[i] )
     k++;
     if (pocet < k ) {
       pocet = k ;
       vysledok = a[i] ;
     }
   }
   return vysledok;
}

int main() {
  int *pole, max = 0, max2 = 0, vysledok = 0;
  pole = alokuj(N);
  nacitaj(pole, N);
  max = maximum(pole, N);
  vysledok = najcastejsi(pole, N); 
  printf("max = %d\nnajcastejsi = %d\n", max, vysledok);
  return 0;
}
