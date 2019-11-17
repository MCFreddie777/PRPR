// uloha2-5.c -- František Gič, 7.10.2019 22:35
#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    if (N < 1 || N > 15 || (N % 2 == 0)) {
        printf("Zly vstup\n");
        return 0;
    } else
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((j == i) || (j == N - i - 1) || (i == (N - 1) / 2) || (j == (N - 1) / 2))
                    printf("*");
                else printf("-");
            }
            printf("\n");
        }

    return 0;
}
