#include <stdio.h>
double q(double x);
double p(double x){
if (x <= 1) 	return 2.0;
   return (p(x-1) + q(x/2));}
double q(double x){
	if (x <= 3)
		return x / (double) 3.0;
	return (q(x-3) * p(x-5));}
int main(){
	double a, b, x;
	do {printf("Zadajte realne cislo (konec pri zadani -1.0)\n");
		scanf("%lf", &x);
		if (x == -1.0) break;
		printf("\np(%.3f) = %.3f\n", x, a = p(x));
		printf("q(%.3f) = %.3f\n\n", x, b = q(x));} 
	while (1);
return 0;
}


