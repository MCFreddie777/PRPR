// uloha7-6.c -- František Gič, 5.11.2019 15:08
#include <stdio.h>
#include <stdlib.h>

void postupka(char *str, char z, int len) {
    if (len <= 0) {
        str[0] = z;
        return;
    }
    for (int i = 0; i < len; i++) {
        str[i] = z;
        if (z == 'z' || z == 'Z') z = z - ('z' - 'a');
        else z++;
    }
}

int main(void) {
    char z[2], *buf;
    int n;

    while (scanf("%s %d", z, &n) == 2) {
        buf = malloc(n + 1); // vyhradim n+1 znakov pre retazec
        postupka(buf, z[0], n);
        printf("%s\n", buf);
        free(buf); // uvolnim vyhradene miesto
    }
    return 0;
}