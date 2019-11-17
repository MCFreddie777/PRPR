//P6.7
//V poli znakov mozu byt aj medzery, preto funkcia gets(), odskusajte si aj scanf()
//Vstup  Eva ma mamu
//       ick 2
//Vystup Evicka ma mamu
 
#include <stdio.h>
#include <string.h>

int vloz_retazec(char *dst, int len, const char *src, int offset)
{
  int dl = strlen(dst), sl=strlen(src);
  if (offset > dl || dl + sl >= len)
    return 1;
  int i;
  for (i = dl+sl; i >= offset+sl; i--)
    dst[i] = dst[i-sl];
  for (i = 0; i < sl; i++)
    dst[offset+i] = src[i];
  return 0;
}

int main() {
  char pole[100], vkladany[30];
  int index, ok;
  
  printf("Zadaj znaky v poli: ");
  //scanf("%s", pole);
  gets(pole);
  printf("Zadaj vkladany retazec a index v poli: ");
  scanf("%s %d", vkladany, &index);
  ok = vloz_retazec(pole, 100, vkladany, index);
  
  if(ok == 0) 
    printf("Upravene pole znakov:%s\n", pole);
  else
    printf("Retazec nie je mozne pridat\n");
  return 0;
}
