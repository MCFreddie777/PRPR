//P4.17
//sucet cislic v zadanom cisle  
#include <stdio.h>
 
int ciferny_sucet1(int x)
{
  int vysledok = 0;
  while (x > 0)
  {
    vysledok += x % 10;
    x /= 10;
  }
  return vysledok;
}

int ciferny_sucet2(int x)
{
  int vysledok;
  for (vysledok = 0; x > 0; x /= 10)
    vysledok += x % 10;
  return vysledok;
}

int ciferny_sucet3(int x)
{
if (x == 0)
return 0;
return x % 10 + ciferny_sucet3(x / 10);
}

int main()
{
    int cislo,suma1, suma2, suma3;
     
    printf("Zadaj cislo: ");
    scanf("%d",&cislo);
     
    suma1 = ciferny_sucet1(cislo);
	suma2 = ciferny_sucet2(cislo);
	suma3 = ciferny_sucet3(cislo);
     
    printf("Sucet cislic zadaneho cisla %d\n : %d\n%d\n%d\n",cislo, suma1, suma2, suma3);
 
    return 0;
}
