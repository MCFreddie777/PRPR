#include <stdio.h>

int main() {
    int a,b,c,d,e;

    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%d\n",e / --a * b++ / c++);
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%d\n",a %= b = d  = 1 + e / 2);
}