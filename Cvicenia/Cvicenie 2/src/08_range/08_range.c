// uloha2-8.c -- František Gič, 7.10.2019 22:35

#include <stdio.h>

int main() {
    int f, g;
    scanf("%d %d", &f, &g);

    for (int i = f; i <= g; i++) {
        if (i % 3 == 0) printf("%d ", i);
    }
    printf("\n");
    return 0;
}