#include <stdio.h>

int main() {
    int i = -1, j = 0, k = 1;
    if (i++ && !j || k++) {
        printf("%d %d %d\n", i, j, k);
        j++;
    }
    printf("%d %d %d\n", i, j, k);
    if (i++ || j && !i || k++) {
        printf("%d %d %d\n", i, j, k);
        j++;
    }
    printf("%d %d %d\n", i, j, k);

    return 0;
}

