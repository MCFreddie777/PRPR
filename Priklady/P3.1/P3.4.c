#include <stdio.h>

int main()
{
	int cislo_n,i;
	double sum = 0.0;
	
	printf("zadaj cislo_n\n");
	scanf("%d", &cislo_n);
	for (i = 1; i <= cislo_n; i++)
	{
        sum = sum + (1 / (double)i);
		if (i == 1)
			printf("\n 1 +");
		        else if (i == cislo_n)
				printf(" (1 / %d)", i);
				else
				printf(" (1 / %d) + ", i);
    }
	printf("\n Suma daneho radu je: %.2lf", sum);
return 0;
}

