#include <stdio.h>

int main() {
    wint i = 2, j = 3, k = 3;
    if ((i++ >= ++j) || (i++ >= k++ || j++ <= ++k)) { // i = 3 >= j=4 || i=4 >= 4
        printf("%d %d %d\n", i, j, k); // 4 4 4
        i += j * k; // 4 += 4 + 4 * 4 20
        printf("%d %d %d\n", i, j, k); // 20 4 4
    }
    return 0;
}