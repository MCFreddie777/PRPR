//kopirovanie obsahu suboru
#include <stdio.h>

int main() 
{
   FILE *fr, *fw;
   int c;

   fr = fopen("list.txt", "r");
   fw = fopen("kopia1.txt", "w");

   while ((c = getc(fr)) != EOF)
      putc(c, fw);

   fclose(fr);
   fclose(fw);
return 0;
}

