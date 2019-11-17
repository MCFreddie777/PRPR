#include <stdio.h>

char lowercase(char c) {
    int val = (int)c;
    if ((val > 64) && (val < 96))   return (char)((int)c + 32);
    else return c;
}

#define LEN 2
int main() {
    char arr[LEN];

    for (int i = 0; i < LEN; i++)
        scanf(" %c", &arr[i]);

    for (int i = LEN -1; i >= 0; i--)
        printf("%c ",lowercase(arr[i]));

    return 0;
}

