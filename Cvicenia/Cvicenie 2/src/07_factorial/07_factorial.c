// uloha2-7.c -- František Gič, 7.10.2019 22:35

#include <stdio.h>

int factorial(int N) {
    int product = 1;
    if (N > 1) {
        product = factorial(N - 1);
    }
    else if (N == 0) return 1;
    return product * N;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", factorial(N));
    return 0;
}