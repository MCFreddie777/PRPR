//P6.11
//Vytvaranie pola vo funkcii - iba dynamicke polia
#include <stdio.h>
#include <stdlib.h>

void init(double **p_f) 
{
    double *a;
    int i;
    a = (double *) malloc(5 * sizeof(double));

    for(i = 0; i < 5; i++) {
        printf("Zadaj %d. cislo: ",i+1);
        scanf("%lf", &a[i]);
    }
    *p_f = a;
}

int main() 
{
   int i;
   double *p_d;  
   init(&p_d);
   for(i = 0; i < 5; i++) {
     printf("Vypis %d. cislo: ",i+1);
     printf("%lf\n", p_d[i]);
   }
   return 0;
}

