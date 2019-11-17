//priklad pozor na inicializovanie premennych v blokoch
#include<stdio.h>
int main ()
{
	int a = 5, c,;
	if (a<100){
	  int b = 4; 
	  c = a+b;
	  printf("a = %d b = %d c = %d\n", a, b,c);//vypis premennych
	}
	b = b+1;
	printf("a = %d b = %d c = %d\n", a, b,c);//vypis premennych

return 0;
}

