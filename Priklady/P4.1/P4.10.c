//P4.10
#include <stdio.h>

int main(void) {
    FILE *fr;
    int c;
    long int pocet = 0;               /* pocet znakov v subore */

    if ((fr = fopen("pismena.txt", "r")) == NULL) {
        printf("Subor pismena.txt sa nepodarilo otvorit\n");
        return 1;
    }

    while ((c = getc(fr)) != EOF)
        pocet++;

    printf("V subore pismena.txt je %ld znakov\n", pocet);

    if (fclose(fr) == EOF)
        printf("Subor pismena.txt sa nepodarilo uzatvorit\n");
    return 0;
}

