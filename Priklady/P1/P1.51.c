#include <stdio.h>
int main()
{
    int cislo;

    printf("Zadaj cele cislo: ");
    scanf("%d",&cislo);
	
	(cislo%2 == 0) ? printf("%d je parne cislo.", cislo) : printf("%d je neparne cislo.", cislo);
	
return 0;
}

