#include<stdio.h>
#define PI 3.14
#define obvod_m(r) (2 * PI * (r))
#define obsah_m(r) (PI * (r) * (r)) 

double obvod_f(double r) 
{
   return 2 * PI  * (r);
}

double obsah_f(double r) 
{
   return PI * (r) * (r);
}

int main() 
{
   double polomer;

   printf("Zadajte polomer kruhu: ");
   scanf("%lf", &polomer);
   printf("\nMakro: obvod: %.2f, obsah: %.2f\n", 
           obvod_m(polomer), obsah_m(polomer));
   printf("Funkcie: obvod: %.2f, obsah: %.2f\n", 
           obvod_f(polomer), obsah_f(polomer));
   return 0;
}

