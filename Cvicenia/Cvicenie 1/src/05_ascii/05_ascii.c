#include <stdio.h>

int capitalize(char c) {
    int val = (int)c;
    if ((val > 96) && (val < 123))   return (char)((int)c - 32);
    else return c;
}

#define LEN 2
int main() {
    char arr[LEN];

    for (int i = 0; i < LEN; i++)
        scanf(" %c", &arr[i]);

    for (int i = 0; i < LEN; i++)
        printf("%c %d\n", capitalize(arr[i]), capitalize(arr[i]));

    return 0;
}

