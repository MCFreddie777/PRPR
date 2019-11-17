// uloha3-1.c -- František Gič, 8.10.2019 10:05
#include <stdio.h>
#include <math.h>

double mocnina(double x, int n) {
    double sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= x;
    }
    return sum;
}

int main() {
    double x;
    int n;
    scanf("%lf %d",&x,&n);

    for (int i = 1; i <= n; i++) {
        printf("%.2lf^%d = %.2lf\n", x, i, mocnina(x, i));
    }
    return 0;
}