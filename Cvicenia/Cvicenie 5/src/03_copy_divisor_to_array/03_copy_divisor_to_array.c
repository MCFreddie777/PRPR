// uloha6-3.c -- František Gič, 29.10.2019 11:00

#include <stdio.h>

int delitele(int x[], int pocetx, int y[], int k) {
    int pocety = 0;

    for (int i = 0; i < pocetx; i++) {
        if (k > 0) {
            if (x[i] != 0 && k % x[i] == 0) {
                y[pocety++] = x[i];
            }
        }
    }
    return pocety;
}


int main() {
    int i, x[10], pocetx;
    scanf("%d", &pocetx);
    for (i = 0; i < pocetx; i++)
        scanf("%d", &x[i]);

    int y[10];
    int pocety = delitele(x, pocetx, y, 24);
    printf("pocety: %d\ny: {", pocety);
    for (int i = 0; i < pocety; i++) {
        if (i > 0)
            printf(", ");
        printf("%d", y[i]);
    }
    printf("}\n");
    return 0;
}