// uloha2-4.c -- František Gič, 7.10.2019 22:35
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    if (N < 1 || N > 15 || (N % 2 == 0)) {
        printf("Zly vstup\n");
        return 0;
    } else
        for (int i = 0; i < (N * 2 - 1); i++) {
            for (int j = 0; j < N; j++) {
                if (i < N) {
                    if (i < j)
                        printf(" ");
                    else
                        printf("*");
                } else if (i == N - 1) {
                    printf("*");
                } else {
                    if (j >= (N - (i - N) - 1))
                        printf(" ");
                    else
                        printf("*");
                }

            }
            printf("\n");
        }

    return 0;
}