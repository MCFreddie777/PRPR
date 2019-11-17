//P4.9
#include <stdio.h>

int main() {
    FILE *fr;
    int c, hodnota = 0;

    if ((fr = fopen("cisla2.txt", "r")) == NULL) {
        printf("Subor cisla2.txt sa nepodarilo otvorit.\n");
        return 1;
    }

    while ((c = getc(fr)) == '$');            /* precita  a ignoruje vsetky znaky $ */

    ungetc(c, fr);  /* vrati prvu cislicu cisla do buffera*/
    fscanf(fr, "%d", &hodnota);

    printf("Nacitane cislo = %d\n", hodnota);

    if (fclose(fr) == EOF) {
        printf("Subor cisla2.txt sa nepodarilo uzavriet.\n");
        return 1;
    }
    return 0;
}

