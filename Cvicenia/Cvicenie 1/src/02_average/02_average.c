#include <stdio.h>

double avg(float a,float b,float c) {
    return (a+b+c)/3.;
}

int main() {
    float x,y,z,p;

    scanf("%f%f%f",&x,&y,&z);
    p = avg(x,y,z);
    printf("Priemer cisel %g %g %g je: %g",x,y,z,p);
}