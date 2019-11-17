//pozor nazov a cesta k suboru
#include <stdio.h>

int main(){
   FILE *f;
   char c;

   f = fopen("Pprvy.txt","r");
   while((c = getc(f)) != EOF)
       putchar(c);

   fclose(f);
   return 0;
}

