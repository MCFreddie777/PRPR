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
            printf("Nespravny vstup.\n");
            continue;
        }

        for (int l = h; l >= d; l--) {
            short velke_pis = (l % 2 == 1) ? 1 : 0;


            int vertical_offset = 0;
            for (int j = 0; j < (v + 1) / 2; j++) {
                int mid = v / 2 + 1;

                for (int m = 0; m < l; m++) {
                    int character_offset = 0;
                    for (int k = 1; k <= v; k++) {
                        if ((k == (mid + (m * v))) || (k <= (mid + j) && k >= (mid - j))) {
                            printf("%c", (97 - (velke_pis * 32)) + character_offset);
                        } else {
                            printf("-");
                        }
                        if (k < mid) character_offset++;
                        else character_offset--;
                    }
                    vertical_offset++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}