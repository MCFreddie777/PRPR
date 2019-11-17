#include <stdio.h>
#include <math.h>

float bmi(float height, float weight) {
    return weight / pow((height/100),2);
}

int main() {
    float h,w;

    scanf("%f %f",&h,&w);
    printf("BMI: %.3f\n",bmi(h,w));
    return 0;
}

