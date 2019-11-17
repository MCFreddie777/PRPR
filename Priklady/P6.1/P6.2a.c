//rekurzivna funkcia
#include <stdio.h>
#include <string.h>
#define MAX  100
void na_male_pismena(char *str)
{
  if (*str)
  {
    if (*str >= 'A' && *str <= 'Z')
      *str = *str - 'A' + 'a';
    na_male_pismena(str + 1);
  } 
}
int main() {
  char s[MAX];
  int i;
  printf("Zadaj znaky retazca: ");
  scanf("%s", s);
  na_male_pismena(s);
  printf("\nZmeneny retazec:%s\n", s);
  return 0;
}
