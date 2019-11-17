// uloha3-2.c -- František Gič, 8.10.2019 10:05
#include <stdio.h>

double nasobok(double x, int n) {
    return x * n;
}

int main() {
    double x;
    int n;
    scanf("%lf %d",&x,&n);

    for (int i = 1; i <= n; i++) {
        printf("%.2lf * %d = %.2lf\n", x, i, nasobok(x, i));
    }
    return 0;
}