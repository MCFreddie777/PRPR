//P4.4
#include<stdio.h>
int main() 
{
   int i, j, n;
   FILE *fw;
   
   if ((fw = fopen("sachovnica.txt", "w")) == NULL) {
		printf("Subor sa nepodarilo vytvorit.\n");
		return 0;
   }
   printf("Zadajte rozmer sachovnice: ");
   scanf("%d", &n);

   for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) 
         if ((i%2 && !(j%2)) || (!(i%2) && j%2))
            putc('#', fw); 
         else
            putc(' ', fw);
      putc('\n', fw);
   }
   if (fclose(fw) == EOF)
	   printf("Subor sa nepodarilo zatvorit.\n");
   return 0;
}

