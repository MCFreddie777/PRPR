// uloha3-7.c -- František Gič, 8.10.2019 10:05

#include <stdio.h>

int main() {
    char c1, c2;
    char *p_c;

    while ((scanf("%c", &c1) == 1) && c1 != '*') {
        p_c = &c2;
        *p_c = c1;
        printf("c1: %c (%p), c2: %c (%p), p_c: %c (%p)\n", c1, &c1, c2, &c2, *p_c, p_c);
    }
    return 0;
}