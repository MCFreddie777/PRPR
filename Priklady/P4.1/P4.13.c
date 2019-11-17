#include <stdio.h>
#include <string.h>

int main() {
    FILE *fr, *fw;
    char s[100];

    /* citanie */
    if ((fr = fopen("subor.txt", "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit na citanie.\n");
        return 1;
    }


    printf("%s\n", fgets(s, 100, fr));
    //printf("%s\n", gets(s));        /* pridanie \n */
    fclose(fr);


    /* zapis */
    if ((fw = fopen("subor_zapis.txt", "w")) == NULL) {
        printf("Subor sa nepodarilo otvorit na zapis.\n");
        return 1;
    }

    fputs(s, fw);
    fputs("\n", fw);  /* pridanie \n */
    puts(s);

    fclose(fw);

    return 0;
}

