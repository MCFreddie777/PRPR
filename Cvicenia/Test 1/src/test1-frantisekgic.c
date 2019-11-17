// test1 - Bc. František Gič, 15.10.2019 10:00

#include <stdio.h>


void kresliObrazec(int s, int r) {
    int mid = r / 2 + 1;
    int offset = -1;
    for (int j = 1; j <= r; j++) {
        offset++;
        for (int k = 1; k <= s; k++) {
            for (int l = 1; l <= (r); l++) {
                if ((l != 1) && (l != r) && (j != 1) && (j != r)) {
                    if ((l == mid) && (j >= mid))
                        printf("*");
                    else if (j < mid && (l == (1 + offset) || l == (r - offset))) {
                        printf("*");
                    } else
                        printf(".");
                } else printf("$");
            }
        }
        printf("\n");
    }
}

int main() {
    int N, v, s, r;

    scanf("%d", &N);
    if ((N < 1 || N > 100)) {
        printf("Nespravny vstup, cislo N nezodpoveda intervalu <1,100>.");
        return 0;
    }


    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &v, &s, &r);
        if ((v < 1) || (v > 7) || (s < 1) || (s > 5) || (r < 1) || (r > 23) || (r % 2 == 0)) {
            printf("Nespravny vstup.");
            return 0;

        }


        for (int j = 0; j < v; j++) {
            kresliObrazec(s, r);
        }

    }


    return 0;
}