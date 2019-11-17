#include<stdio.h>

   int main(){
   int a[50], velkost, cislo, i, poz;

   printf("Zadajte velkost pola (max 50): ");
   scanf("%d", &velkost);
   printf("Zadajte %d prvkov pola:\n", velkost);
   for(i=0; i<velkost; i++)
      scanf("%d", &a[i]);

   printf("Zadajte poziciu a cislo na vlozenie: ");
   scanf("%d %d", &poz, &cislo);

   i = velkost++;
   while(i > poz) {
     a[i] = a[i-1];
     i--;
   }
   a[i] = cislo;
   printf("Pole po vlozeni prvku:\n");
   for(i=0; i<velkost; i++)
      printf(" %d",a[i]);
   return 0;
} 

