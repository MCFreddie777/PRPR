// uloha7-7.c -- František Gič, 5.11.2019 15:09

#include <stdio.h>
#include "../common/string_helper.h"

int main() {
    int len, offset;
    char dst[100], src[100];

    scanf("%s %d %s %d", dst, &len, src, &offset);
    if (strinsert(dst, len, src, offset))
        printf("Nepodarilo sa vlozit retazec.\n");
    else
        printf("%s", dst);
    return 0;
}