#include <stdio.h>
#include <stdlib.h>
#define N ('Z' - 'A' + 1)

int main() {
   int i;
   char hist[N], slovo[100];

   scanf("%s", slovo);      /* nacitanie slova */
   for (i = 0; i < N; i++)   /* inicializacia hist */
      hist[i] = 0;

   i = 0;
   /* naplnenie hist */
   while (i < 100 && slovo[i] != '\0') {
      hist[toupper(slovo[i]) - 'A']++;
	  i++; }
for(i = 0; i < N; i++)    /* vypis hist */
	 if(hist[i] != 0)
		 printf("%c: %d\n", i+'A', hist[i]);

   return 0;
}

