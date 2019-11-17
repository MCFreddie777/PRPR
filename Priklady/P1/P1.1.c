#include<stdio.h>
int main ()
{
	int n, n1;	//deklaracia premennych
	char c;
	float f;
	double x;
	
	n = 10;		//inicializacia premennych 
	n1 = 15;
	c = 'b';
	f = 3.1415926535897932384;
	x = 3.1415926535897932384;
	 
	printf("n = %d n1 = %d\n", n, n1);//vypis premennych	
	printf("c = %c, c+1 = %c\n", c, c+1);
	printf("f = %f, x = %.16lf\n", f, x);
return 0;
}

