// uloha5-8.c -- František Gič, 26.10.2019 15:44

#include <stdio.h>

int cifsucet(int x) {
    if (x == 0) {
        return 0;
    }
    return (x%10) + cifsucet(x/10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("a: %d\n", cifsucet(n));
    return 0;
}