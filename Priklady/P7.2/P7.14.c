#include <stdio.h>
int g [ 10 ][ 10 ], c [ 10 ];
int main()
{
  int i, j;
  while ( scanf ("%d", & i ) > 0 )
  {
    g[i/10][i%10]++;
    c[ i/10 ]++;
  }
  for (i = 0 ; i < 10 ; i++)
    if ( c[i] )
    {
      printf ("%d | ", i );
      for (j = 0 ; j < 10 ; j++)
        while ( g [ i ][ j ] > 0 )
        {
          printf ("%d", j );
          g[ i ][ j ]--;
        }
      printf( "\n" );
    }
  return 0;
}

