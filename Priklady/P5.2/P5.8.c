#include <stdio.h> 
int main() { 
  FILE *fw; 
  if ((fw = fopen("strojopis.txt", "w")) == NULL) { 
    printf("Subor sa nepodarilo otvorit\n"); 
    return 1; 
  } 
  while (1) { 
    int c; 
    c = getchar(); 
    if(c == '$') break; 
    putc(c, fw); 
  } 
  if (fclose(fw) == EOF) { 
    printf("Subor sa nepodarilo zatvorit\n"); 
    return 1; 
  } 
  return 0; 
} 

