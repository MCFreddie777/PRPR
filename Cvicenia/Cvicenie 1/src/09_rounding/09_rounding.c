#include <stdio.h>
#include <math.h>

int main() {
    double num;

    scanf("%lf", &num);
    printf("%d %d\n",(int)floor(num),(int)round(num));
}