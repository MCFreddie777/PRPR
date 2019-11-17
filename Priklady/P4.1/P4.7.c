//P4.7
#include <stdio.h>

int main() 
{
   FILE *fr;
   double x, y, z;

   fr = fopen("cisla.txt", "r");
   if(fscanf(fr, "%lf %lf %lf", &x, &y, &z) == 3)
      printf("sucet: %lf \n", x + y + z);
   else 
      printf("Subor neobsahuje 3 realne cisla\n");
   fclose(fr);
return 0;
}

