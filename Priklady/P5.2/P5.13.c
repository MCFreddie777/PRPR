#include<stdio.h>

int najvacsie_zaporne(int *a, int n){
  int i, max = -1;
  for (i = 0; i < n; i++){
    if (a[i] < 0 && (max < 0 || a[max] < a[i]))
    max = i;
  }
  return max;
}

int najcastejsi( int *a , int n){
  int i, j, k, pocet=0, vysledok ;
  for (i = 0; i < n ; i++)
  {
    for (j = k = 0; j < n; j++)
      if ( a[j] == a[i] )
        k++;
    if (pocet < k ){
      pocet = k ;
      vysledok = a[i] ;
    }
  }
  return vysledok;
}

int main() { 
   int x[] = {12,67,-56,60,-12,34,67,123};
   int nz, naj;
   nz = najvacsie_zaporne(x, 8);
   naj = najcastejsi(x, 8);
   printf("%d %d",nz, naj);
return 0;
}

