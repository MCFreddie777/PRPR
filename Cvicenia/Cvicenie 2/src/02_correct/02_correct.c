// Bc. Frantisek Gic
#include <stdio.h>

int main() {
    int len,num,last;
    short correct = 1;

    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        if (scanf("%d", &num) == 1) {
            if (i == 0 && ((num < 0) || (num > 10))) correct = 0;
            else {
                if ((num > (2*last)) || (num < (last / 2))) correct = 0;
            }
            last = num;
        }
        else return 0;
    }

    if (correct)
        printf("Postupnost je spravna\n");
    else
        printf("Postupnost nie je spravna\n");
    return 0;
}