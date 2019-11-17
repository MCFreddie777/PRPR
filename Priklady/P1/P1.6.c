#include <stdio.h>

int main(void)
{
  double realne;
  int cele;

  printf("Zadaj realne cislo: ");
  scanf("%lf", &realne);
  printf("Vypis cisla bez desatinnej casti:\n");
  printf("1.: %.0lf (format tlace - zaokruhluje)\n", realne);
  printf("2.: %d (explicitna typova konverzia)\n", (int)realne);
  cele = realne;
  printf("3.: %d (implicitna typova konverzia)\n",cele);
return 0;
}

