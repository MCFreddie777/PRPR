//P6.5 vkladanie znaku do stredu retazca s parnym poctom znakov
#include <stdio.h>
#include <string.h>

void vloz_do_stredu(char *str, char c)
{
  int i, n = strlen(str);
  for (i = n-1 ; i >= n / 2; i--)
    str[i + 1] = str[i];
  str[n / 2] = c;
}

int main() {
  char znak, retazec[100];
  
  printf("Zadaj retazec a vkladany znak: ");
  scanf("%s %c", retazec, &znak);
  vloz_do_stredu(retazec, znak);
  printf("\nUpraveny retazec:%s\n", retazec);
  return 0;
}

