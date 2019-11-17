//
// Created by František Gič on 08/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 50
#define MAX_RECORDS 100
#define DATEFORMAT "rrrrmmdd"

/**
 * Function opens a file from static path
 *
 * @param f file pointer with file open
 * @return file pointer
 */
FILE *open_file(FILE *f) {
    if (((f = fopen("autobazar.txt", "r")) == NULL)) {
        printf("Neotvoreny subor\n");
    }
    return f;
}

/**
 * Function which reads the given file line by line to a buffer
 * and then allocates array of arrays of string (database) and fills it with
 * data about records
 * If the database does already contain values, it will free the memory and allocate again
 *
 * @param f pointer to a file to be read
 * @param database pointer to a char *** memory where the data from file should be stored
 * @param db_size integer, current size of a database parameter
 */
void parse_file(FILE *f, char ***database, int *db_size) {

    if (*db_size > 0) {
        rewind(f);
        for (int i = 0; i < *db_size; i++) {
            for (int j = 0; j < 5; j++) {
                free(database[i][j]);
            }
            free(database[i]);
        }
        *db_size = 0;
    }

    char temp[MAX_LINE_LENGTH];
    char **buffer = malloc(sizeof(char *));
    int buffer_size = 0;

    // read every single line into the buffer
    while (fgets(temp, MAX_LINE_LENGTH, f) != NULL) {
        temp[strlen(temp) - 1] = '\0';

        if (strlen(temp) > 1) {
            buffer = (char **) realloc(buffer, (buffer_size + 1) * sizeof(char *));
            buffer[buffer_size] = (char *) malloc(strlen(temp));
            strcpy(buffer[buffer_size], temp);
            buffer_size++;
        }
    }

    // parse every five buffer lines into database
    for (int i = 0; i < buffer_size; i = i + 5) {
        database[*db_size] = (char **) malloc(5 * sizeof(char *));

        for (int j = 0; j < 5; j++) {
            database[*db_size][j] = (char *) malloc(strlen(buffer[i + j]));
            buffer[i + j][strlen(buffer[i + j]) - 1] = '\0';
            strcpy(database[*db_size][j], buffer[i + j]);
        }
        *db_size = *db_size + 1;
    }
}

/**
 * Prints all the information about the car sellers and sold cars
 *
 * @param database allocated memory with data
 * @param db_size integer size of a database parameter
 */
void print_employees(char ***database, int db_size) {
    for (int i = 0; i < db_size; i++) {
        printf("meno priezvisko: %s\n", database[i][0]);
        printf("SPZ: %s\n", database[i][1]);
        printf("typ auta: %s\n", database[i][2]);
        printf("cena: %s\n", database[i][3]);
        printf("datum: %s\n", database[i][4]);
        printf("\n");
    }
}

/**
 * Function parses string date into an integer array of 3 separate integers - year, month, day.
 *
 * @param string_date pointer to string in "yyyymmdd" format
 * @param date integer array where
 * @return integer
 */
void parse_date(const char *string_date, int date[3]) {

    // year
    int multiplier = 1000;
    date[0] = 0;
    for (int i = 0; i < 4; i++) {
        date[0] += (string_date[i] - '0') * multiplier;
        multiplier /= 10;
    }

    // month
    multiplier = 10;
    date[1] = 0;
    for (int i = 4; i < 6; i++) {
        date[1] += (string_date[i] - '0') * multiplier;
        multiplier /= 10;

    }

    // day
    multiplier = 10;
    date[2] = 0;
    for (int i = 6; i < 8; i++) {
        date[2] += (string_date[i] - '0') * multiplier;
        multiplier /= 10;

    }
}

/**
 * Function calculates if there is >365 range between two string dates
 *
 * @param date_from string date in the further past than date_to in "yyyymmdd" format
 * @param date_to string pointer with date in "yyyymmdd" format
 * @return
 */
short at_least_year(char *date_from, char *date_to) {

    int from[3], to[3];
    parse_date(date_from, from);
    parse_date(date_to, to);

    long from_timestamp = from[2] + (from[1] * 31) + (from[0] * 365);
    long to_timestamp = to[2] + (to[1] * 31) + (to[0] * 365);

    return (short) (to_timestamp - from_timestamp > 365);
}

/**
 * Prints name, license plate of a sold car and bonus of a employees
 * who work in a company for more than a year
 * Bonus multiplier depends on whether the car was new or used
 *
 * @param database allocated memory with data
 * @param db_size integer size of a database parameter
 */
void bonus_employees(char ***database, int db_size) {
    char *date = (char *) malloc(strlen(DATEFORMAT));

    if (scanf("%s", date) == 1 && (strlen(date) == 8)) {
        for (int i = 0; i < db_size; i++) {
            if (at_least_year(database[i][4], date)) {
                printf("%s ", database[i][0]);
                printf("%s ", database[i][1]);
                double multiplier = (database[i][2][0] == '1') ? 0.023 : 0.051;
                printf("%.2lf\n", atof(database[i][3]) * multiplier);
            }
        }
    }
}

/**
 * Creates array of license plates from database
 * If array already exists, it will free the memory and reallocate
 *
 * @param db allocated memory with data
 * @param db_size integer size of a database parameter
 * @param arr_spz array of strings where the license plates should be stored to
 * @return array of strings with license plates
 */
char **create_spz(char ***db, int db_size, char **arr_spz, int *spz_size) {
    if (arr_spz != NULL) {
        for (int i = 0; i < db_size; i++) {
            free(arr_spz[i]);
        }
        free(arr_spz);
    }

    arr_spz = (char **) malloc(db_size * sizeof(char *));

    for (int i = 0; i < db_size; i++) {
        arr_spz[i] = (char *) malloc(6);
        strcpy(arr_spz[i], db[i][1]);
    }

    *spz_size = db_size;
    return arr_spz;
}

/**
 * Prints the array of license plates with spaces in between
 *
 * @param arr_spz array of strings with license plates
 * @param size size of the arr_spz parameter
 */
void print_spz(char **arr_spz, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < strlen(arr_spz[i]); j++) {
            printf("%c", arr_spz[i][j]);
            if (j == 1 || j == 4) printf(" ");
        }
        printf("\n");
    }
}

/**
 * Iterates the array of license plates and
 * prints the most occurring character with its occurrence number
 * Uses histogram filled with occurrence values of each character
 *
 * @param arr_spz array of strings with license plates
 * @param size size of the arr_spz parameter
 */
void freq_spz(char **arr_spz, int size) {
    int range = (int) 'Z' - (int) '0';
    int occurrences[range];

    // initialize the char occurrence array
    for (int i = 0; i < range; i++) {
        occurrences[i] = 0;
    };

    // increase letter count for each character
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < strlen(arr_spz[i]); j++) {
            occurrences[arr_spz[i][j] - (int) '0']++;
        }
    }

    char max;
    int max_occur = 0;

    // find the first most occurring character and it occurrence count
    for (int i = 0; i < range; i++) {
        if (occurrences[i] > max_occur) {
            max_occur = occurrences[i];
            max = (char) (i + '0');
        }
    };

    printf("%c %d\n", max, max_occur);
}

/**
 * Iterates the array of strings and
 * prints first two characters of each string
 * which is a palindrome
 *
 * @param arr_spz array of strings with license plates
 * @param size size of the arr_spz parameter
 */
void palindrome_spz(char **arr_spz, int size) {
    for (int i = 0; i < size; i++) {

        short palindrome = 1;
        int length = strlen(arr_spz[i]);

        for (int j = 0; j < length / 2; j++) {
            if (arr_spz[i][j] != arr_spz[i][length - j - 1]) palindrome = 0;
        }

        if (palindrome)
            printf("%c%c\n", arr_spz[i][0], arr_spz[i][1]);
    }
}

/**
 * Uses histogram to find number of cars being sold from which district
 * Prints the district with most cars sold
 *
 * @param arr_spz array of strings with license plates
 * @param size size of the arr_spz parameter
 */
void okres_spz(char **arr_spz, int size) {
    char ***sold_cars = (char ***) malloc(size * sizeof(char **));
    int sold_size = 0;
    int max_occurence = 0;

    for (int i = 0; i < size; i++) {

        // check if district abbreviation exists in array, if yes, remember its index
        int existing_id = -1;
        for (int j = 0; j < sold_size; j++) {
            if (sold_cars[j][0][0] == arr_spz[i][0] && sold_cars[j][0][1] == arr_spz[i][1]) {
                existing_id = j;
            }
        }

        // if exists, increase its occurrence number
        if (existing_id >= 0) {
            int increased_occurences = atoi(sold_cars[existing_id][1]) + 1;
            if (increased_occurences > max_occurence)
                max_occurence = increased_occurences;
            sold_cars[existing_id][1][0] = (char) (increased_occurences + '0');
        } else {

            // if record does not exist in the array, create new and allocate the memory
            sold_cars[sold_size] = (char **) malloc(2 * sizeof(char *));
            sold_cars[sold_size][0] = (char *) malloc(2);
            sold_cars[sold_size][1] = (char *) malloc(1);

            sold_cars[sold_size][0][0] = arr_spz[i][0];
            sold_cars[sold_size][0][1] = arr_spz[i][1];
            sold_cars[sold_size][1][0] = '1';

            sold_size++;
        }
    }

    for (int i = 0; i < sold_size; i++) {
        int occurrence = atoi(sold_cars[i][1]);
        if (occurrence == max_occurence)
            printf("%s %d\n", sold_cars[i][0], occurrence);
    }
}

char **zmaz_spz(char **arr_spz, int *size) {
    char start_char;
    short match = 0;

    char **new_spz = (char **) malloc(sizeof(char *));
    int size_new = 0;

    if (scanf(" %c", &start_char) == 1) {

        for (int i = 0; i < *size; i++) {
            if (arr_spz[i][0] == start_char) {
                match = 1;
            } else {
                new_spz = (char **) realloc(new_spz, (size_new + 1) * sizeof(char *));
                new_spz[size_new] = arr_spz[i];
                size_new++;
            }
        }

        if (match == 0) {
            free(new_spz); // unused memory, we'll free it
            printf("Zhoda nebola zistena");
            return arr_spz;
        } else {
            *size = size_new;

            if (size_new == 0)
                new_spz = NULL;

            free(arr_spz);
            return new_spz;
        }
    }
    return arr_spz;
}

void hist_spz(char **arr_spz, int size) {
    int range = (int) 'Z' - (int) 'A';
    int occurrences[range];

    // initialize the char occurrence array
    for (int i = 0; i < range; i++) {
        occurrences[i] = 0;
    };

    // increase letter count for last two characters
    for (int i = 0; i < size; i++) {
        occurrences[arr_spz[i][5] - (int) 'A']++;
        occurrences[arr_spz[i][6] - (int) 'A']++;
    }

    // print all characters which occur in string and its occurrence number (sorted alphabetically)
    for (int i = 0; i < range; i++) {
        if (occurrences[i] > 0) {
            printf("%c:%d\n", (char) (i + 'A'), occurrences[i]);
        }
    };
}

char cezar(char c, int k) {
    char cezar_char = (char) (c + k);
    int bound = (int) ('Z' - k);

    if (cezar_char > bound) {
        cezar_char = (char) ('A' + (c - bound - 1));
    }

    return cezar_char;
}

char **cezar_spz(char **arr_spz, int *size) {
    int k;

    char **encrypted_spz = (char **) malloc((2 * (*size)) * sizeof(char *));
    int new_size = 0;

    if ((scanf(" %d", &k) == 1) && k <= 25) {

        for (int i = 0; i < *size; i++) {
            encrypted_spz[i * 2] = (char *) malloc(strlen(arr_spz[i]));
            encrypted_spz[(i * 2) + 1] = (char *) malloc(4);
            encrypted_spz[i * 2] = strcpy(encrypted_spz[i * 2], arr_spz[i]);

            encrypted_spz[(i * 2) + 1][0] = cezar(arr_spz[i][0], k);
            encrypted_spz[(i * 2) + 1][1] = cezar(arr_spz[i][1], k);
            encrypted_spz[(i * 2) + 1][2] = cezar(arr_spz[i][5], k);
            encrypted_spz[(i * 2) + 1][3] = cezar(arr_spz[i][6], k);

            for (int j = 0; j < (int) strlen(encrypted_spz[i * 2]); j++) {
                printf("%c", encrypted_spz[i * 2][j]);
                if (j == 1 || j == 4) printf(" ");
            }
            printf("\n%s\n", encrypted_spz[(i * 2) + 1]);

            new_size++;
        }

        *size = new_size;
        free(arr_spz);
        return encrypted_spz;
    }
    return arr_spz;
}

int main() {
    char mode;
    FILE *f = NULL;

    // Database of records (global for the whole program)
    char ***db = (char ***) malloc(MAX_RECORDS * sizeof(char **));
    int db_size = 0;

    // Database of license plates
    char **arr_spz = NULL;
    int spz_size = 0;

    // Welcome message
    while (scanf("%c", &mode) == 1) {
        switch (mode) {
            case ('v'): {
                f = open_file(f);
                parse_file(f, db, &db_size);
                print_employees(db, db_size);
                break;
            }
            case ('o'): {
                if (f != NULL) {
                    parse_file(f, db, &db_size);
                    bonus_employees(db, db_size);
                }
                break;
            }
            case ('n'): {
                if (f != NULL) {
                    arr_spz = create_spz(db, db_size, arr_spz, &spz_size);
                }
                break;
            }
            case ('s'): {
                if (arr_spz != NULL) {
                    print_spz(arr_spz, spz_size);
                } else {
                    printf("Pole nie je vytvorene\n");
                }
                break;
            }
            case ('m'): {
                if (arr_spz != NULL) {
                    freq_spz(arr_spz, spz_size);
                } else {
                    printf("Pole nie je vytvorene\n");
                }
                break;
            }
            case ('p'): {
                if (arr_spz != NULL) {
                    palindrome_spz(arr_spz, spz_size);
                } else {
                    printf("Pole nie je vytvorene\n");
                }
                break;
            }
            case ('z'): {
                if (arr_spz != NULL) {
                    okres_spz(arr_spz, spz_size);
                }
                break;
            }
            case ('x'): {
                if (arr_spz != NULL) {
                    arr_spz = zmaz_spz(arr_spz, &spz_size);
                }
                break;
            }
            case ('h'): {
                if (arr_spz != NULL) {
                    hist_spz(arr_spz, spz_size);
                } else {
                    printf("Pole nie je vytvorene\n");
                }
                break;
            }
            case ('c'): {
                if (arr_spz != NULL) {
                    arr_spz = cezar_spz(arr_spz, &spz_size);
                }
                break;
            }
            case ('k'): {
                fclose(f);
                return 0;
            }
            case ('\n'): {
                break;
            }
            default: {
                break;
            }
        }
    }
}
