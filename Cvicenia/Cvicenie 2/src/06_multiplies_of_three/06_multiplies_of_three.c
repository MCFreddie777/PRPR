// uloha2-6.c -- František Gič, 7.10.2019 22:35
#include <stdio.h>

int main() {
    int N, number, counter = 0;
    scanf("%d", &N);

    while (scanf("%d", &number) == 1) {
        if (number > 0 && number <= 100) counter++;
    };
    printf("%d\n",counter);
    return 0;
}