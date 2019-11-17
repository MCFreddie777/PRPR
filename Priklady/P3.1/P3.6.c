// pozor chyba - nespravne umiestnenie funkcie 
//(v case volania funkcie nie je ani deklarovana)

#include<stdio.h>
int main(void)
{
  double x, y;
  scanf("%lf %lf", &x, &y);
  printf("Obvod: %lf\n", obvod_obdlznika(x,y));
  return 0;
}

double obvod_obdlznika(double a, double b)
{
  double sucet = a + b;
  return 2.0 * sucet;
}
