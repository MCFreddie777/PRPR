// uloha6-9.c -- František Gič, 16.11.2019 16:16

// NOT DONE TODO

#include <stdio.h>

int samohlasky(char *s) {

    char *z = "aeiouy";

    int pocet = 0;
    if (s[0] == '\0')
        return 0;
    while (*z != *s && *z != '\0' && z++)
        pocet += 1 + samohlasky((&s[0]) + 1);

    return pocet;
}

int main() {
    char buf[500];
    while (scanf("%s", buf) > 0)
        printf("%d\n", samohlasky(buf));
    return 0;
}