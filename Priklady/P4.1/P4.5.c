//P4.5
# include <stdio.h>

int main() 
{
   FILE *fr;
   int c;

   fr = fopen("list.txt", "r");
   while ((c = getc(fr)) != '\n') 
      putchar(c); 
   putchar(c); 
   fclose(fr);
return 0;
}

