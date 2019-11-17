// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>

int main() {
    double n;
    FILE *f;

    scanf("%lf", &n);
    f = fopen("nasobky.txt", "w+");

    for (int i = 1; i <= 10; i++) {
        fprintf(f, "%2d * %.2lf = %.2lf\n", i, n, i * n);
    }

    fclose(f);
    return 0;
}