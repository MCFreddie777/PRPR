//P6.1
#include <stdio.h>
#include <string.h>
#define MAX  51          /*max. dlzka retazca*/
int main() {
  char s[MAX];
  int i;
  printf("Zadaj slovo: ");
  scanf("%s", s);
  printf("Nove slovo je:%s", s);
    for (i = strlen(s) - 2;  i >= 0;  i--)
      putchar(s[i]); 
    putchar('\n');
return 0;
}

