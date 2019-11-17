//P4.0
#include <stdio.h>

int main(){
   FILE *f;
   char c;

   f = fopen("P4.0.c","r");
   while((c = getc(f)) != EOF)
       putchar(c);

   fclose(f);
   return 0;
}

