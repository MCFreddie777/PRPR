// uloha5-8.c -- František Gič, 26.10.2019 15:44

#include <stdio.h>

int neparne(int n) {
    if (n == 0)
        return 0;
    if ((n % 2 == 1)) {
        return n + neparne(n-1);
    }
    return neparne(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("a: %d\n", neparne(n-1));
    return 0;
}