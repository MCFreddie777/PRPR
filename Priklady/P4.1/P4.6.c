//P4.6
#include <stdio.h>

int main() 
{
   FILE *fw;
   int i;

   fw = fopen("cisla1.txt", "w");
   for (i = 1; i <= 10; i++) 
      fprintf(fw, "%d\n", i);
   fclose(fw);
return 0;
}

