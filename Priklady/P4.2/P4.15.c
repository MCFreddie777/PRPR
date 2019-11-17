//P4.15
#include<stdio.h>

void print_bin(unsigned int x)
{
  long long i = 1, vysledok = 0;
  for (; x > 0; x /= 2, i *= 10)
    vysledok = vysledok + (x % 2) * i;
  printf("%llu\n", vysledok);
}

int main()
{	long long cislo;
    printf("Zadaj cele cislo do 1 000 000: ");
    scanf("%lld",&cislo);
	print_bin(cislo);
    printf("\n");
    return 0;
}

