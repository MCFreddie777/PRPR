//odstranene male pismena z retazca
#include <stdio.h>
#include <stdlib.h>

int odstran_male_pismena( char *str )
{
  int i,j ;
  for (i = j = 0; str[i] ; i++)
    if ( str[i] < 'a' || str[i] > 'z' )
      str[ j++ ] = str[ i ];
  str[ j ] = 0;
  return j;
}


int main() {
  char retazec[100];
  int odstranene = 0;
  printf("Zadaj vstupny retazec: ");
  scanf("%s", retazec);
  odstranene = odstran_male_pismena(retazec);
  printf("\nRetazec po uprave:%s\n", retazec);
  printf("Bolo odstranenych %d znakov\n", odstranene);
  return 0;
}
