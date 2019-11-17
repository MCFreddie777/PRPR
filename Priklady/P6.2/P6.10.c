#include <stdio.h>

void ahoj() {
	printf("Ahoj\n");
}

void cau() {
	printf("Cau\n");
}

int main() {
   int c;
   void (* p_f)();    /* definicia ukazovatela na funkciu */

   printf(" A Ahoj / C Cau / K Koniec programu\n");
   while((c = getchar()) != 'K') {
      if (c == 'A') p_f = ahoj;
      else if (c == 'C') p_f = cau;
	else continue;

	(*p_f)();		// volanie funkcie
   }
   return 0;
}

