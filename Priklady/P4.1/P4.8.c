#include <stdio.h>
int main()
{
    FILE *fr;
    char nazov_suboru[15];
    int ch;
    printf("Zadaj nazov suboru na otvorenie \n");
    scanf("%s", nazov_suboru);
    /*  otvorenie suboru na citanie s testovanim*/ 
    fr = fopen(nazov_suboru, "r");
    if (fr == NULL)    {
        printf("Subor sa neda otvorit \n");
        exit(0);    }
    ch = fgetc(fr);
    while (ch != EOF)    {
        printf ("%c", ch);
        ch = fgetc(fr);
    }
    fclose(fr);
return 0;
}

