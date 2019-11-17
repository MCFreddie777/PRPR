// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>

char *f();

int main(void) {
    short tag = 0;
    FILE *f = fopen("html.txt", "r");

    char c;
    while ((c = getc(f)) != EOF) {
        if (c == '<') {
            tag = 1;
        }
        else if (!tag) {
            putchar(c);
        }
        else if (c == '>') {
            tag = 0;
        }
    }

    fclose(f);
}