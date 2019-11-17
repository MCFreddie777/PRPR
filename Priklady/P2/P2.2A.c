//pozor na chybne pouzitie znamienka = pri podmienkach
#include<stdio.h>
int main ()
{
	int a,b;
	a = 15;
	b = 5;
	if(a == b){
	  printf("a = %d b = %d\n", a, b);
	}
	printf("a = %d b = %d\n", a+1, b+1);
return 0;
}
