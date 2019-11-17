#include <stdio.h>

int main() 
{
   FILE *fr, *fw;
   int c;

   fr = fopen("znaky.txt", "r");
   fw = fopen("kopia1.txt", "w");

   c = getc(fr);/*citanie 1.znaku */
   putc(c, fw); /*zapis 1.znaku */ 
   putc(getc(fr), fw); /*citanie a zapis 2.znaku */

   fclose(fr);
   fclose(fw);
return 0;
}


