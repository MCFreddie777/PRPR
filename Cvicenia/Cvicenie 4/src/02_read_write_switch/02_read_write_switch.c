// uloha5-2.c -- František Gič, 22.10.2019 10:32

#include <stdio.h>

int main() {
    char mode;
    FILE *fr;
    char readFilePath[] = "znak.txt";
    FILE *fw;
    char writeFilePath[] = "novy.txt";


    if ((fr = fopen(readFilePath, "r")) == NULL) {
        printf("Subor %s sa nepodarilo otvorit.\n", readFilePath);
        return 0;
    };

    mode = getchar();
    char c;
    if (mode == 's') {
        if ((fw = fopen(writeFilePath, "w+")) == NULL) {
            printf("Subor %s sa nepodarilo otvorit.\n", writeFilePath);
            return 0;
        };
        while ((c = getc(fr)) != EOF) {
            putc(c, fw);
        }
        if ((fclose(fw) == EOF)) printf("Subor %s sa nepodarilo zatvorit.\n", writeFilePath);
    } else {
        while ((c = getc(fr)) != EOF) {
            printf("%c", c);
        }
    }


    if ((fclose(fr) == EOF)) printf("Subor %s sa nepodarilo zatvorit.\n", readFilePath);
    return 0;
}