// bonus-test1 - Bc. František Gič, 15.10.2019 11:00

#include <stdio.h>

int main() {
    int N, v, h, d;

    scanf("%d", &N);
    if ((N < 1 || N > 100)) {
        printf("Nespravny vstup, cislo N nezodpoveda intervalu <1,100>.");
        return 0;
    }


    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &v, &h, &d);
        if ((v < 3) || (v % 2 == 0) || (h < 1) || (d < 1)) {
            printf("Nespravny vstup.");
            return 0;
        }


        for (int j = 1; j <= d; j++) {  // pocet opakovani na riadky  j % 2 == velke / male pismena
            short velke_pis = (j % 2 == 1) ? 1 : 0;

            int mid = v / 2 + 1;
            int offset = -1;
            for (int k = 1; k < v - 1; k++) { // riadky
                offset++;

                for (int l = 1; l <= h; l++) { // pocet obrazcov v riadku
                    int pismeno = 97 - (velke_pis * 32);

                    for (int m = 1; m <= v; m++) { // jeden obrazec

                        if ((m == (mid - offset)) || (m == mid) || (m == (mid + offset))) {
                            printf("%c", pismeno++);
                        } else {
                            printf("-");
                        }
                    }
                }
                printf("\n");
            }
        }
    }


    return 0;
}