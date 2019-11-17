#include <stdio.h> 
int main(void) 
{ 
  int i = 20, j = 4; 
  if ((i %= j) && ++j == 5) 
  printf ("Logicky sucin\n");       
  printf("i: %d  j: %d\n", i, j);   
return 0;
}

