//pozor nazov a cesta k suboru
#include <stdio.h>

int main()
{
   FILE *f;
   char c;

   if ((f = fopen("prvy.txt","r"))== NULL)
   printf("Subor sa nepodarilo otvorit.\n");
   
   while((c = getc(f)) != EOF)
       putchar(c);

   fclose(f);
   return 0;
}
