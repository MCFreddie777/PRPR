// uloha7-1.c -- František Gič, 5.11.2019 10:00

#include <stdio.h>

int main() {
    int ok1, c1, ok2, c2, posun;
    FILE *f1 = fopen("resources/cisla1.txt", "rt");
    FILE *f2 = fopen("resources/cisla2.txt", "rt");
    FILE *fout = fopen("resources/vysledok.txt", "w+");
    ok1 = fscanf(f1, "%d ", &c1);
    ok2 = fscanf(f2, "%d ", &c2);

    while ((ok1 > 0) || (ok2 > 0)) {
        posun = 0;

        if ((ok1 == 1) && (ok2 == 1)) {
            posun = (c1 < c2) ? 1 : 2;
        } else {
            posun = (ok1 > 0) ? 1 : 2;
        }

        if (posun == 1) {
            fprintf(fout, "%d ", c1);
            ok1 = fscanf(f1, "%d ", &c1);
        } else if (posun == 2) {
            fprintf(fout, "%d ", c2);
            ok2 = fscanf(f2, "%d ", &c2);
        }
    }
    fclose(fout);
    return 0;
}