 /*Dané sú tri polia: pole a[] obsahujúce na celıch èísel (typ int) usporiadanıch od najmenšieho po najväèšie, pole b[] obsahujúce nb celıch èísel (typ int) usporiadanıch od najmenšieho po najväèšie a pole c[] dåky na+nb prvkov typu int bez vyplnenıch hodnôt.

Napíšte funkciu spoj(), ktorá prvky vstupnıch polí a[] a b[] spojí do vıstupného po¾a c[], ktoré po vykonaní funkcie bude obsahova na+nb èísel z polí a[] a b[], ktoré budú usporiadané od najmenšieho po najväèšie.

Vstup: a[] = { -2,3,4,4,6 }, b[] = { -4,-1,2,3,5,6,7 }

Vıstup: c[] = { -4,-2,-1,2,3,3,4,4,5,6,6,7 }

Funkciu pouite v programe, ktorı naèíta postupnosti do polí a[] a b[] zo vstupu a vıslednú postupnos c[] vypíše na vıstup.

Pokúste sa implementova funkciu spoj() tak, aby: nepouívala cyklus a pouívala len 1 podmienku.
*/
#include <stdio.h>

// spoji usporiadane polia a a b do pola c, aby zostali vsetky prvky pola c usporiadane
void spoj(int *a, int na, int *b, int nb, int *c)
{
  // riesenie -- bez pouzitia cyklov
  
  if (na > 0 && nb > 0 && *a < *b || nb == 0)
  {
    *c = *a; spoj(a + 1, na - 1, b, nb, c + 1);
  }
  else
  {
    *c = *b; spoj(a, na, b + 1, nb - 1, c + 1);
  }
}


int main()
{
  int i, a[1000], na, b[1000], nb, c[2000];
  
  scanf("%d", &na);
  for (i = 0; i < na; i++)
    scanf("%d", &a[i]);
  scanf("%d", &nb);
  for (i = 0; i < nb; i++)
    scanf("%d", &b[i]);
  
  spoj(a, na, b, nb, c);
  for (i = 0; i < na+nb; i++)
    printf("%d ", c[i]);
  printf("\n");

  return 0;
}
