#include <stdio.h>
int main (void)
{
	int cislo, reverz_cislo;

	printf ("Zadaj cele cislo: ");
	scanf ("%d", &cislo);
	
	while ( cislo != 0 ) {
		reverz_cislo = cislo % 10;
		printf ("%d", reverz_cislo);
		cislo = cislo / 10;
	}
	printf ("\n");
return 0;
}

