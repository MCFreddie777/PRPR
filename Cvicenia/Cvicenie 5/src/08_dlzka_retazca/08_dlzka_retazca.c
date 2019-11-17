// uloha6-8.c -- František Gič, 16.11.2019 13:56

#include <stdio.h>

int dlzka(char *buf) {
    if ((buf[0] != '\0')) {
        return 1 + dlzka((&buf[0]) + 1);
    }
    return 0;
}

int main() {
    char buf[500];
    int max = 0, i;

    while (scanf("%s", buf) > 0) {
        printf("%d ", i = dlzka((char *) &buf));
        if (i >= max)
            max = i;
    }
    printf("\nNajdlhsie slovo ma %d znakov\n", max);
    return 0;
}