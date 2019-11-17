// uloha5-7.c -- František Gič, 26.10.2019 15:44

#include <stdio.h>

int nacitaj(double *x, double *y) {
    return scanf("%lf %lf", x, y) == 2;
}

void vypocitaj(double x, double y, double *obsah, double *obvod) {
    *obsah = x * y;
    *obvod = 2 * (x + y);
}

int main() {
    double x, y, obsah, obvod;
    if (!nacitaj(&x, &y)) {
        printf("Zly vstup\n");
        return 0;
    }
    vypocitaj(x, y, &obsah, &obvod);

    printf("Obsah: %.3lf\n", obsah);
    printf("Obvod: %.3lf\n", obvod);
    return 0;
}