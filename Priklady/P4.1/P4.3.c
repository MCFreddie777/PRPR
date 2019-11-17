//P4.3
#include <stdio.h>
int main() {
   double x, suma;
   int i;
   FILE *fr;

   if ((fr = fopen("cisla.txt", "r")) == NULL) {
      printf("Subor cisla.txt, sa nepodarilo otvorit.\n");
      return 0;
   }
   suma = 0.0;
   i = 0;
   while (fscanf(fr, "%lf", &x) ==1) {
      printf("%.3lf\n", x);
      suma += x;
      i++;
   }
	printf("Priemer nacitanych cisel je: %.3lf\n", suma/i);
	
	if(fclose(fr) == EOF)
   printf("Subor sa nepodarilo zatvorit.\n");
return 0;
}
