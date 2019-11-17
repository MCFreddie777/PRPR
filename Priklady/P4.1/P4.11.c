//P4.11
#include <stdio.h>

int main(void) {
    FILE *fr, *fw;
    int c;
    if ((fr = fopen("pismena.txt", "r")) == NULL) {
        printf("Subor pismena.txt sa nepodarilo otvorit\n");
        return 0;
    }
    if ((fw = fopen("Vpismena.txt", "w")) == NULL) {
        printf("Subor Vpismena.txt se nepodarilo otvorit\n");
        return 0;
    }
    while ((c = getc(fr)) != EOF) {//nacitanie po znaku do konca suboru
        if (c >= 'A' && c <= 'Z') putc(c, fw); // ak je nacitany znak velke pismeno vypise ho do suboru fw
    }
    if (fclose(fr) == EOF)
        printf("Subor pismena.txt se nepodarilo zatvorit\n");
    if (fclose(fw) == EOF)
        printf("Subor Vpismena.txt sa nepodarilo zatvorit\n");
    return 1;
}

