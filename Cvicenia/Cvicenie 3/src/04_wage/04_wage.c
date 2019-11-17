// uloha3-7.c -- František Gič, 8.10.2019 10:05

#include <stdio.h>

double tyzdenna_mzda(double h_mzda, double hod) {
    double unpaid = 0, paid = 0;
    double wage = 0;
    if (hod - 60 > 0) {
        unpaid = hod - 60;
        wage += unpaid * 2 * h_mzda;
        paid = unpaid;
    }
    if (hod - paid - 40 > 0) {
        unpaid = hod - paid - 40;
        wage += unpaid * 1.5 * h_mzda;
        paid += unpaid;
    }
    wage += (hod - paid) * h_mzda;
    return wage;
}

int main() {
    int n;
    double total = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        double current_wage = tyzdenna_mzda(a, b);
        total += current_wage;
        printf("Hod. mzda: %.2lf Euro/hod, hodin: %.2lf, spolu: %.2lf Euro\n", a, b, current_wage);
    }
    printf("Celkova mzda: %.2lf Euro\n", total);
    return 0;
}