#include <stdio.h>

int main() {
    int n; double sum = 0;

    if (scanf("%d",&n) == 1) {
        for (int i = 1; i <= n; i++) {
            sum += 1. / i;
        }
    }

    printf("Sucet: %lf\n",sum); // 1/1 + 1/2 + 1/3 = 1 + 0.5 + 0.33
    return 0;
}