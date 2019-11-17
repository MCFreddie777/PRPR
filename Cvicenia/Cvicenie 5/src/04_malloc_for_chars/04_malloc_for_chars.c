// uloha6-4.c -- František Gič, 29.10.2019 11:14

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d\n", &n) == 1) {
        char *str = (char *) malloc(n * sizeof(char) + 1);

        for (int i = 0; i < n; i++) {
            scanf("%c", &str[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            printf("%c", str[i]);
        }

    }
    printf("\n");
    return 0;
}