#include <stdio.h>
 
 void vypis1(int p) {
   if (p == 0)
      return;
 	printf("%d ", p);
	vypis1(p-1);
}

void vypis2(int p) {
   if (p == 0)
      return;
   	vypis2(p-1);
	printf("%d ", p);
}

int main()
{	
	int x;

    printf("Zadaj cele cislo: ");
    scanf("%d",&x);
	
	vypis1(x);
	printf("\n");
    vypis2(x);
    return 0;
}

