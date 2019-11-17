#include<stdio.h>
double obvod_obdlznika(double a, double b)
{
  double sucet = a + b;
  return 2.0 * sucet;
}

int main(void)
{
  double x, y;
  scanf("%lf %lf", &x, &y);
  printf("Obvod: %lf\n", obvod_obdlznika(x,y));
  return 0;
}
