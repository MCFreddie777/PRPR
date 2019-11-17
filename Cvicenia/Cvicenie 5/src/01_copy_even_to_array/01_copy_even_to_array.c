// uloha6-1.c -- František Gič, 29.10.2019 10:05

/*
 * Napíšte funkciu int parne(int x[], int pocetx, int y[]),
 * ktorá skopíruje všetky párne čísla z poľa x do poľa y
 * v poradí v akom sa nachádzajú v poli x a vráti počet prvkov poľa y.
 * Argument pocetx určuje počet prvkov poľa x.

    Môžete predpokladať, že argument y, bude mať dostatočnú veľkosť pre všetky párne prvky.

    Ukážka volania:
    x = {4, 7, 1, 3, 2, 5, 6}
    pocetx = 7
    pocety = parne(x, pocetx, y);  // volanie funkcie
    pocety: 3                      // vypis vysledku
    y: {4, 2, 6}
 */
#include <stdio.h>

int parne(int x[], int pocetx, int y[]) {
    int pocety = 0;

    for (int i = 0; i < pocetx; i++)
        if (x[i] % 2 == 0) {
            y[pocety++] = x[i];
        }
    return pocety;
}


int main() {
    int i, x[10], pocetx;

    scanf("%d", &pocetx);

    for (i = 0; i < pocetx; i++)
        scanf("%d", &x[i]);

    int y[10];
    int pocety = parne(x, pocetx, y);

    printf("pocety: %d\ny: {", pocety);

    for (i = 0; i < pocety; i++) {
        if (i > 0)
            printf(", ");
        printf("%d", y[i]);
    }
    printf("}\n");
    return 0;
}