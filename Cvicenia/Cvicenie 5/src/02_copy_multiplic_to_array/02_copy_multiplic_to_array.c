// uloha6-2.c -- František Gič, 29.10.2019 10:15

#include <stdio.h>
#include <stdlib.h>

int nasobky(int x[], int pocetx, int y[], int k) {
    int pocety = 0;

    for (int i = 0; i < pocetx; i++)
        if (k > 0) {
            if (x[i] % k == 0)
                y[pocety++] = x[i];
        } else {
            if (k == 0 && x[i] == 0) {
                y[pocety++] = 0;
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
    int pocety = nasobky(x, pocetx, y, 2);
    printf("pocety: %d\ny: {", pocety);
    for (i = 0; i < pocety; i++) {
        if (i > 0)
            printf(", ");
        printf("%d", y[i]);
    }
    printf("}\n");
    return 0;
}