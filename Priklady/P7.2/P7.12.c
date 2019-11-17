#include <stdio.h>

int magicky_stvorec(int **a, int n)
{
  int i, j, sucet = 0, k;
  for (j = 0; j < n; j++) // sucet v riadku 0
    sucet += a[ 0 ][ j ];
  for (i = 1; i < n; i++) // riadky
  {
    for (k = 0, j = 0; j < n; j++)
      k += a[i][j] ;
  if (k != sucet )
    return 0 ;
  }
  for (j = 0; j < n; j++) // stlpce
  {
    for (k = 0, i = 0; i < n; i++)
      k += a[i][j] ;
    if ( k != sucet )
  return 0 ;
  }
  for (k = 0, i = 0; i < n; i++) // hlavna diagonala
    k += a[i][i] ;
  if ( k != sucet )
    return 0 ;
  for (k = 0, i = 0; i < n; i++) // vedlajsia diagonala
    k += a[i][n-i-1] ;
  if ( k != sucet )
    return 0 ;
  return 1 ;
}

int main(void)
{
  //doplnte chybajucu cast programu...
  
  return 0;
}
