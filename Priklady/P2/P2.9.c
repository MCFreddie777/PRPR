#include <stdio.h>
int main()
{	
	int operacia, n1, n2, vysledok;
	
	printf("Aku operaciu chcete vykonat?\n");
	printf("stlac 1 na scitanie\n");
	printf("stlac 2 na odcitanie\n");
	printf("stlac 3 na nasobenie\n");
	printf("stlac 4 na delenie\n");
	scanf("%d", &operacia);
	printf("Zadaj prve cislo\n");
	scanf("%d", &n1);
	printf("Zadaj druhe cislo\n");
	scanf("%d", &n2);
	switch(operacia)
	{
		case 1: vysledok  = n1+n2;
		printf("Vysledok scitania je %d\n", vysledok);
		break;
		case 2: vysledok  = n1-n2;
		printf("Vysledok odcitania je %d\n", vysledok);
		break;
		case 3: vysledok  = n1*n2;
		printf("Vysledok nasobenia je %d\n", vysledok);
		break;
		case 4: vysledok  = n1/n2;
		printf("Vysledok delenia je %d\n", vysledok);
		break;
		default:printf("Chyba");
	}
return 0;
	
}	


