#include <stdio.h>

int main() {
   FILE *fr;
   int c, dlzka, max_dlzka;

   if ((fr = fopen("list.txt", "r")) == NULL) {
      printf("Subor sa nepodarilo otvorit.\n");
      return 0;
   }

   dlzka = max_dlzka = 0;
   while((c= getc(fr)) != EOF) {
      dlzka++;
      if (c>='a' && c<='z') 
         c -= ('a'- 'A');
      putchar(c);
      if (c == '\n') {
      	dlzka--;
         if (max_dlzka < dlzka)
            max_dlzka = dlzka;
         dlzka = 0;
      }
   }
if (max_dlzka < dlzka)
      max_dlzka = dlzka;

   printf("Max. dlzka: %d\n", max_dlzka);
   if (fclose(fr) == EOF) 
      printf("Subor sa nepodarilo zatvorit\n");
   return 0;
}

