#include <stdio.h> 
// kni�nica potrebna ku generatoru
#include <time.h>
#include <stdlib.h>

int main(void) { 
  int i, nahodne_cislo; 
  
// inicializacia generatora nahodnych cisiel 
  srand( time( 0 ) ); 
  printf ("Generovane cisla su: \n"); 
  
  for (i=0; i<=50; i++) {
  // /* generovanie cisla v rozsahu 1 - 100 */ 
    nahodne_cislo = rand()%100 + 1; 
    printf ("%d \n",nahodne_cislo); 
  } 
  return 0; 
} 

