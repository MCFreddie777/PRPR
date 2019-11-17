// uloha6-6.c -- František Gič, 13.11.2019 18:30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILEPATH_LENGTH 100
#define MAX_BUFFER_LENGTH 1001

/**
 * Opens file and returns a pointer to it
 * In case of file not found, exits the program
 *
 * @param file pointer to a file to be opened
 * @param file_path string path to a file
 * @return
 */
FILE *openFile(FILE *file, char *file_path) {
    if ((file = fopen(file_path, "r")) == NULL)
        exit(-1);
    return file;
}

/**
 * Closes the file
 *
 * @param f pointer to a file to be closed
 */
void closeFile(FILE *f) {
    if (fclose(f) == EOF)
        exit(-1);
}

/**
 * Prints the histogram table header (letters A - Z)
 */
void printTableHeader() {
    printf("  ");
    for (int i = 'A'; i <= 'Z'; i++)
        printf("  %c", i);
    printf("\n");
}

void printHist(char *buffer, int *line_count) {
    int range = 'Z' - 'A';
    int *hist = (int *) calloc(range, sizeof(int));

    printf("%2d", ++*(line_count));
    for (int i = 0; i < strlen(buffer); i++) {
        if ((toupper(buffer[i]) >= 'A') && (toupper(buffer[i]) <= 'Z')) {
            ++hist[toupper(buffer[i]) - 'A'];
        }
    }

    for (int i = 0; i <= range; i++) {
        printf(" %2d", hist[i]);
    }
    printf("\n");
}


int main() {
    char *file_path = (char *) malloc(MAX_FILEPATH_LENGTH);

    if (scanf("%s", file_path) == 1) {
        int line_count = 0;
        FILE *file;

        file = openFile(file, file_path);
        printTableHeader();

        char *line = (char *) malloc(MAX_BUFFER_LENGTH);
        while (fgets(line, MAX_BUFFER_LENGTH, file) != NULL)
            printHist(line, &line_count);

        closeFile(file);
    }
    return 0;
}