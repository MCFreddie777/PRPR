// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>
#define OBVOD(x,y) (2*(x+y))

char *f();

int main(void) {
    int neparne[6] = {1,3,5,7,9,11}, *p_1, *p_2;
    p_1 = &neparne[2];
    p_2 = &neparne[3];
    printf("%d %d\n",*p_1,*p_2);
    printf("%d\n",OBVOD(*(++p_1),*(++p_2)));
    printf("%d\n",OBVOD(++(*p_1),++(*p_2)));

}