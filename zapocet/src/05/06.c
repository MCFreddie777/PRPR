#include <stdio.h>

short cislo3(int c, int *cs) {
    short occ = 0;

    int r = c;
    while (r != 0) {
        int zv = r % 10;
        if (zv == 3) occ = 1;
        *cs += zv;
        r = r / 10;
    }
    return occ;
};

int main() {
    int cs = 0;
    short je = cislo3(54, &cs);
    printf("%d %d\n", cs, je);
}