#include <stdio.h>

void uprav_zlomok(int *citatel, int *menovatel) {
    int i;
    for (i = 2; i <= *citatel; i++) {

        if (*citatel % i == 0 && *menovatel % i == 0) {
            *citatel = *citatel / i; *menovatel = *menovatel / i ;
            uprav_zlomok(citatel,menovatel);
        }
    }
}

int main() {
    int x, y;
    x = 1001;
    y = 1287;
    uprav_zlomok(&x, &y);
    printf("Zakladny tvar zlomku: %d/%d\n", x, y);
    return 0;
}