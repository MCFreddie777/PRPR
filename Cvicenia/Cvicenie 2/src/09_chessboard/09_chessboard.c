// uloha2-9.c -- František Gič, 7.10.2019 22:35
#include <stdio.h>

short toggle_switch(short sw) {
    if (sw == 0) return 1;
    else return 0;
}

int main() {
    int N, P;
    short sw = 0;
    scanf("%d %d", &N, &P);

    for (int i = 0; i < N * P; i++) {
        if (((N % 2 == 0 && i % P != 0) || (N % 2 == 1 && i % P == 0)) && i != 0) {
            sw = toggle_switch(sw);
        }
        for (int j = 0; j < N * P; j++) {
            if (j % P == 0 && j != 0)
                sw = toggle_switch(sw);

            if (sw == 0) printf("*");
            else printf("-");
        }
        printf("\n");
    }
    return 0;
}
