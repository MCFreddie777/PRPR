//Pozor pri inicializacii max
#include <stdio.h>
#define POCET  50 

int main(void)
{
   int  pole[POCET];  // pole 50 prvkov, indexy od 0 po 49
   int n, i, max;
	
   printf("Zadaj pocet prvkov n = ");  
   scanf("%d", &n);
   for (i = 0; i < n ; i++) {
      printf("%d. prvok:  ", i + 1);	
      scanf("%d", &pole[i]);
   }
   max = pole[0];  // hladanie maxima 
   for (i = 0; i < n ; i++) {
      if (pole[i]>max)  
		max = pole[i];
   }
   printf("Maximum je %d \n",  max); 
return 0;
}

