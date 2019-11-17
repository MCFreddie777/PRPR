// uloha7-8.c -- František Gič, 5.11.2019 15:09

#include <stdio.h>
#include "../common/string_helper.h"

int main() {
    char str[100];
    int n, offset;
    scanf("%s %d %d", str, &n, &offset);
    if (strdelete(str, n, offset))
        printf("Nepodarilo sa vymazat znaky.\n");
    else
        printf("%s", str);
    return 0;
}