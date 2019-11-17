// uloha5-4.c -- František Gič, 26.10.2019 15:44

#include <stdio.h>

int main() {
    FILE *f;
    char path[] = "text.txt";

    if ((f = fopen(path, "r")) == NULL) {
        printf("Subor %s sa nepodarilo otvorit.\n", path);
        return 0;
    };

    char c;
    int whitespace = 0;
    while ((c = getc(f)) != '*') {
        if (c == 'X' || c == 'x') printf("Precital som X\n");
        if (c == 'Y' || c == 'y') printf("Precital som Y\n");
        if (c == '$' || c == '#' || c == '&') printf("Precital som riadiaci znak\n");
        if (c == ' ') whitespace++;
    }
    printf("Koniec\n");
    printf("Pocet precitanych medzier: %d\n",whitespace);


    return 0;
}