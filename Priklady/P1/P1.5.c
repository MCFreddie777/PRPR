#include <stdio.h>
int main()
{
    int cislo;

    printf("Zadaj cele cislo: ");
    scanf("%d",&cislo);
	
    // Ak je cislo delelitelne bez zvysku cislom 2 
    if(cislo%2 == 0)
        printf("%d je parne cislo.", cislo);
    else
        printf("%d je neparne cislo.", cislo);
		
return 0;
}

