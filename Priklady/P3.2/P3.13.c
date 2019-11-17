#include <stdio.h>
double xn(double x, int n)
{
  double v = 1.0;
  int i;
  for (i = 0; i < n; i++)
    v = v*x;
  return v;
}

int main()
{
    double mocnenec, vysledok;
    int mocnitel;
    printf("Zadaj mocnenca a mocnitela : ");
    if (scanf("%lf %d", &mocnenec, &mocnitel)== 2){
    		vysledok = xn(mocnenec, mocnitel);
          printf("Mocnina cisla %lf umocneneho na %d je %lf\n",mocnenec, mocnitel, vysledok);
	}
     else
          printf("Zly vstup\n");
     
     return 0;
}

