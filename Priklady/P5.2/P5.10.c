#include<stdio.h>

int main() { 
   int x[] = {12,67,56,60,88,34,123};
   int hodnota, velkost, i, najdene = -1;
   scanf("%d", &hodnota);
   velkost = sizeof(x) / sizeof(int);//iba pri statickom poli!!!

   i = 0;
   while (najdene < 0 && i < velkost) {
      if (x[i] == hodnota)
         najdene = i; 
      else
         i++;
   }

   if (najdene != -1) 
      printf ("%d je na pozicii %d.\n", hodnota, i); 
   else 
      printf ("%d sa v poli nenachadza.\n", hodnota); 
   return 0; 
} 

