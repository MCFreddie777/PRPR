#include <stdio.h>

void vypocitaj_obdlznik(double a, double b, double *obvod, double *obsah) {
    *obvod = 2 * (a + b);
    *obsah = a * b;
}

int main() {
    double a = 2.0, b = 3.5, obvod, obsah;
    vypocitaj_obdlznik(a, b, &obvod, &obsah);
    printf("%lf %lf\n", obvod, obsah);
    return 0;
}