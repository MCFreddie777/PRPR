// Bc. Frantisek Gic
#include <stdio.h>

int main() {
    int len;
    double num, min, max;

    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        if (scanf("%lf", &num) == 1) {
            if (i == 0) {
                min = num;
                max = num;
            }
            if (num < min) min = num;
            if (num > max) max = num;
        }
        else return 0;
    }
    printf("Minimum: %.2lf\n",min);
    printf("Maximum: %.2lf\n",max);
    return 0;
}