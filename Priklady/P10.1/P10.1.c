#include <stdio.h>	
int main()
{
   int a = 102, b = 91;
   a = a ^ b;
   printf("Po prvom a ^ b = %d\n", a );		//61
   a = a ^ b;
   printf("Po druhom a ^ b = %d\n", a );		//102 (povodna hodnota a)		
return 0;
}

