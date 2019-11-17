// uloha3-5.c -- František Gič, 8.10.2019 10:05

#include <stdio.h>

int power(int n, int x) {
    int temp = 1;
    for (int i = 0; i < x; i++) {
        temp *= n;
    }
    return temp;
}

int armstrong(int x) {
    int sum = 0, digit_counter = 0, temp = x;

    while (temp > 0) {
        temp = temp / 10;
        digit_counter++;
    }

    temp = x;
    while (temp > 0) {
        sum += power(temp % 10, digit_counter);
        temp = temp / 10;
    }

    return (x == sum);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (armstrong(x))
            printf("%d je Armstrongove cislo\n", x);
        else
            printf("%d nie je Armstrongove cislo\n", x);
    }
    return 0;
}