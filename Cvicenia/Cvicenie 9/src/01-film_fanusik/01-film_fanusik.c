// uloha9-1.c -- František Gič, 19.11.2019 10:06

#include <stdio.h>
#include <string.h>

struct Osoba {
    char *meno;
    int pocet;
};

struct Osoba o[100];
int no;

int main() {
    char buf[100];
    int i, maxi = -1;
    
    while (scanf("%s", buf) != -1) {
        
        for (i = 0; i < no; i++)
            if (!strcmp(buf, o[i].meno)) {
                o[i].pocet++;
                if (o[i].pocet > o[maxi].pocet)
                    maxi = i;
                break;
            }
        
        if (i == no) {
            o[no].meno = strdup(buf);
            o[no].pocet = 1;
            no++;
            if (maxi < 0)
                maxi = 0;
        }
    }
    printf("%s\n", o[maxi].meno);
    
    return 0;
}