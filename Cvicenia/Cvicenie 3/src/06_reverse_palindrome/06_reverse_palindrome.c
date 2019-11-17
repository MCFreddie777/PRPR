// uloha3-6.c -- František Gič, 8.10.2019 10:05

#include <stdio.h>

long reverzne_cislo(long x) {
    long reverse = 0;
    while (x != 0) {
        reverse = (reverse * 10) + x % 10;
        x = x / 10;
    }
    return reverse;
}

int palindrome(long x) {
    return (x == reverzne_cislo(x));
}

int main() {
    long x;
    while (scanf("%ld", &x) == 1) {
        printf("%ld\n", reverzne_cislo(x));
        if (palindrome(x))
            printf("Cislo %ld je palindrom\n", x);
        else
            printf("Cislo %ld nie je palindrom\n", x);
    }
    return 0;
}