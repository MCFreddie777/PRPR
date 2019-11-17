#include <stdio.h>

long double rect_volume(long double height,long double width,long double depth) {
    return height*width*depth;
}


int main() {
    long double a,b,c;

    scanf("%Lf %Lf %Lf",&a,&b,&c);
    printf("Objem: %.3Lf\n",rect_volume(a,b,c));
    return 0;
}

