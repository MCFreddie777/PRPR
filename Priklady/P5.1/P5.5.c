#include <stdio.h>
#include <stdlib.h>
int *alokuj(int pocet)
{
   return (int *) malloc(pocet * sizeof(int));
}

void nacitaj(int *pole, int pocet)
{
   int i;
   for(i = 0; i < pocet; i++) {
      printf("%d-te cislo: ", i);
      scanf("%d", pole + i);
   }
}

float priemer(int *pole, int pocet)
{
   int i, suma = 0;
   for(i = 0; i < pocet; i++)
      suma += *(pole + i);
   return (float) suma / (float) pocet;
}

void vypis(int *pole, int pocet)
{
   int i;
   for(i = 0; i < pocet; i++)
      printf("%d, ", *(pole + i));
}

int main()
{
   int *pole, n;

   printf("Zadajte pocet cisel: ");
   scanf("%d", &n);
   if ((pole = alokuj(n)) == NULL) {
      printf("Nepodarilo sa alokovat pole.\n");
      return 1;
   }
   nacitaj(pole, n);
   printf("Priemer cisel: \n");
   vypis(pole, n);
   printf("je %.3f.\n", priemer(pole, n));
   free(pole);
   return 0; 
}



