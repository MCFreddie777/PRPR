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

void sucin(int *p, int n, int *nasob)
{
  int i;

  for (i = 0; i < n; i++)
    *nasob *= *(p + i);
}

int main() {
  int *cisla, nasob=1;
  cisla = alokuj(N);
  nacitaj(cisla, N);
  sucin(cisla, N, &nasob);
  printf("sucin je: %d\n", nasob);
  return 0;
}
