#include <stdio.h>

int main(void)
{
  int cislo1, cislo2;
  int i,
      d,                        /* dolna hranica */
      h;                        /* horna hranica */

  printf("Zadaj dve kladne cele cisla: ");
  scanf("%d %d", &cislo1, & cislo2);

  /* najdenie hornej a dolnej hranice */
  d = (cislo1 < cislo2) ? cislo1 : cislo2;
  h = (cislo1 >= cislo2) ? cislo1 : cislo2;

  /* zaokrouhlenie na najblizsie vyssie cele parne cislo */
  d += (d % 2) ? 1 : 0;

  for (i = d;  i <= h;  i += 2)
    printf("%d  ", i);

  printf("\n");
return 0;
}

