#include<stdio.h>
int main()
{
   int rok;
 
   printf("Zadajte rok: ");
   scanf("%d", &rok);
 
	if(((rok % 4 == 0)&&(rok % 100 != 0))||(rok % 400 == 0))
	  printf("%d je priestupny rok", rok);
	else
	  printf("%d nie je priestupny rok", rok);

return 0;
}

