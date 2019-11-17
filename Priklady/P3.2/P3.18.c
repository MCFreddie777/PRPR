#include<stdio.h>

void kruh(double polomer, double *obvod, double *obsah)
{
*obvod = 2 * 3.14159 * polomer; // 2*PI*r
*obsah = 3.14159 * polomer * polomer; // PI*r^2
}
int main(void)
{
double r, o, s;
printf("Zadaj polomer: ");
scanf("%lf", &r);
kruh(r, &o, &s);
printf("\nObvod kruhu: %lf\n", o);
printf("Obsah kruhu: %lf\n", s);
return 0;
}

