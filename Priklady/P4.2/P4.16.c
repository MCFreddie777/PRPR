//P4.16
#include<stdio.h>

void print_bin(int x)
{
if (x > 1)
print_bin(x / 2);
printf("%d", x % 2);
}

int main()
{	long long cislo;
    printf("Zadaj cele cislo do 1 000 000: ");
    scanf("%lld",&cislo);
	print_bin(cislo);
    printf("\n");
    return 0;
}
