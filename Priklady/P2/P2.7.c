#include <stdio.h>
int main (void)
{
  char c;
  printf ("Zadaj znak:\n");
  scanf ("%c", &c);

  if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
	printf ("Abecedny znak\n");
  else if ( c >= '0' && c <= '9' )
	printf ("Cislica\n");
  else
	printf ("Specialny znak\n");
return 0;
} 

