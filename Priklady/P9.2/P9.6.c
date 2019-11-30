//P9.6
#include <stdio.h>

int main()
{
      int pole[5]= {1,3,5,7,9}, *p_x, *p_y;

	p_x = &pole[1];
	p_y = &pole[2];  
	printf("%d %d\n",*p_x, *p_y);
	printf("%d %d\n", *(p_x++), *(p_y++));
	printf("%d %d\n", ++(*p_x), ++(*p_y));	
return (0);
}

