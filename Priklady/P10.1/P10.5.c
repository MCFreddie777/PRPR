#include <stdio.h>
void vypis_dvojkove(unsigned x)
{
	if (x>0) 
	{	
		vypis_dvojkove(x>>1);
		printf("%d",x&1);
	}
}
int main()
{
	int x;
	
	printf("Zadaj cislo v desiatkovej sustave: ");
	scanf("%d",&x);
	
	printf("Povodne cislo: %d\n", x);
	printf("Cislo v dvojkovej sustave:");
	vypis_dvojkove(x);
return 0;
}

