#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
int main()
{
char veta[256] = "hlavna veta";
char retazec[256] = "nejaky text";
int pozicia = 4;
char* vysledna_veta = (char *) malloc((strlen(veta)+strlen(retazec)+1)*sizeof(char));
strncpy(vysledna_veta,veta,pozicia);
vysledna_veta[pozicia] = '\0'; 
strcat(vysledna_veta, retazec);
strncat(vysledna_veta, veta+pozicia, strlen(veta)-pozicia);
printf("%s\n", vysledna_veta); 
return 0;
} 

