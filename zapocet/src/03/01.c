#include <stdio.h>

double *p_f();

#define PI 3.14
#define OBVOD(r) (2*PI*r)

int main() {
    int i = 17, j = 7;
    if ((i %= j) || ++j == 0)
        printf("Logicky sucet\n");
    printf("i = %d j= %d\n", i, j);


    printf("%d\n",OBVOD(1));
    return 0;
}