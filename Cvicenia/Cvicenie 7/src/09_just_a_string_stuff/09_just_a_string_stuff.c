// uloha7-9.c -- František Gič, 5.11.2019 15:09

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/string_helper.h"

// tieto funkcie mozes pouzit vo svojom programe
//int strinsert(char *dst, int len, const char *src, int offset);
//int strdelete(char *str, int n, int offset);

#define MAX_INPUT_SIZE 512
#define MAX_STRING_SIZE 512

char *read(char *string, char *word) {
    int max;
    
    if (scanf("%s %d", word, &max) != 2) abort();
    string = (char *) realloc(string, max);
    strcpy(string, word);
    free(word);
    
    printf("%s\n", string);
    return string;
}

char *ins(char *dst, char *src) {
    int n;
    scanf("%d %s", &n, src);
    
    if (strinsert(dst, (int) (strlen(src) + strlen(dst) + 1), src, n) ||
        (n != 0 && strlen(dst) == 0))
        printf("%s do retazca nie je mozne vlozit podretazec od zvolenej pozicie\n", dst);
    else {
        printf("%s\n", dst);
    }
    return dst;
}

char *del(char *string) {
    int n, offset;
    scanf("%d %d", &offset, &n);
    
    if (strdelete(string, n, offset) || strlen(string) == 0)
        printf("%s z retazca nie je mozne vymazat znaky\n", string);
    else {
        printf("%s\n", string);
        
    }
    return string;
}

int main() {
    
    char command[MAX_INPUT_SIZE];
    char *string = (char *) malloc(50);
    
    while (scanf("%s ", command) == 1) {
        
        char *string_argument = (char *) malloc(MAX_STRING_SIZE);
        
        if (!strcmp(command, "read")) {
            string = read(string, string_argument);
        }
        if (!strcmp(command, "ins")) {
            string = ins(string, string_argument);
        }
        if (!strcmp(command, "del")) {
            string = del(string);
        }
        
    }
    
    return 0;
}