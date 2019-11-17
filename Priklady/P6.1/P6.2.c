//Pozor, format %s umoznuje nacitanie retazca iba po prvy prazdny znak. 
//Ak by sme chceli spracovat viacslovny retazec napr. JanKo MrKVIcka tento format nebude postacovat ( 
#include <stdio.h>
#include <string.h>
#define MAX  100
void na_male_pismena(char *str)
{
  int i;
  for (i = 0; str[i]; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] - 'A' + 'a';
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
