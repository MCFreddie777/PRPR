//P6.6
//vstup:najneposlusnejsi 2 3
//poziciu pocitame od 0
 
#include <stdio.h>
#include <string.h>

int odstran_znaky(char *str, int n, int offset)
{
  int i, len = strlen(str);
  if (len-offset < n)
    return 1;
  for (i = offset+n; i <= len; i++)
    str[i-n] = str[i];
  return 0;
}

int main() {
  char retazec[100];
  int odstraneny, index, ok;
  
  printf("Zadaj retazec, pocet odstranenych znakov a index : ");
  scanf("%s %d %d", retazec, &odstraneny, &index);
  ok = odstran_znaky(retazec, odstraneny, index);
  if(ok == 0) 
    printf("\nUpraveny retazec:%s\n", retazec);
  else
    printf("Uvedeny pocet znakov nie je mozne odstranit\n");
  return 0;
}
