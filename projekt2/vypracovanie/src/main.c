//
// Created by František Gič on 27/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 200

/*
 * Singly linked list
 */
typedef struct ListItem {
    char *category;                    // kategoria ponuky
    char *city;                        // miesto ponuky
    char *address;                     // ulica
    int area;                          // rozloha v m2
    int price;                         // cena
    char *description;                 // popis
    struct ListItem *next;
} LISTITEM;

/**
 * Helper function that returns a copy of source string in lowercase
 * @param str source string
 * @return copy of source string in lowercase
 */
char *strlwr(char *str) {
    
    // Create a copy of string
    char *temp = (char *) malloc(strlen(str));
    strcpy(temp, str);
    
    unsigned char *p = (unsigned char *) temp;
    
    // Iterate through characters and lowercase it
    while (*p) {
        *p = tolower((unsigned char) *p);
        p++;
    }
    
    return temp;
}

/**
 * Allocates the memory for each member of a struct
 * Sizes given statically in the project assignment
 *
 * @param item A list item
 */
void alloc_list_item(LISTITEM **item) {
    (*item)->category = (char *) malloc(50);
    (*item)->city = (char *) malloc(50);
    (*item)->address = (char *) malloc(100);
    (*item)->description = (char *) malloc(200);
}

/**
 * Procedure that frees memory of all members of linked list item
 *
 * @param item linked list item
 * @param free_itself boolean - whether the item itself should be freed
 */
void free_item(LISTITEM **item, short free_itself) {
    free((*item)->category);
    free((*item)->city);
    free((*item)->address);
    free((*item)->description);
    if (free_itself) {
        free(*item);
    }
}

/**
 * Frees memory of whole linked list
 *
 * @param list first item in linked list
 */
void free_list(LISTITEM **list) {
    LISTITEM *prev = NULL;
    LISTITEM *act = *list;
    
    while (act != NULL) {
        prev = act;
        act = act->next;
        free_item(&prev, 1);
    }
    
    *list = NULL;
}

/**
 * Procedure that allocates memory and reads input into the list item
 * Uses POSIX getline function
 *
 * @param item linked list item to be read to
 * @param f input stream
 */
void read_item(LISTITEM **item, FILE *f) {
    
    alloc_list_item(item);
    
    // Buffer size and buffer to be read to
    char *line = NULL;
    unsigned long int line_size = 0;
    
    getline((&(*item)->category), &line_size, f);
    getline((&(*item)->city), &line_size, f);
    getline((&(*item)->address), &line_size, f);
    
    getline(&line, &line_size, f);
    (*item)->area = atoi(line);
    
    getline(&line, &line_size, f);
    (*item)->price = atoi(line);
    
    getline((&(*item)->description), &line_size, f);
    
    (*item)->next = NULL;
}

/**
 * Makes a copy of all list item members
 *
 * @param dst destination list item
 * @param src source list item to be cloned
 */
void cpy_item(LISTITEM **dst, LISTITEM *src) {
    free_item(dst, 0);
    alloc_list_item(dst);
    
    strcpy((*dst)->category, src->category);
    strcpy((*dst)->city, src->city);
    strcpy((*dst)->address, src->address);
    (*dst)->price = src->price;
    (*dst)->area = src->area;
    strcpy((*dst)->description, src->description);
}

/**
 * Pretty print of linked list item
 * Format specified in project's assignment
 *
 * @param item linked list item
 * @param index
 */
void print_single_item(LISTITEM *item, int *index) {
    printf("%d.\n", ++(*index));
    printf("kategoria ponuky: %s", item->category);
    printf("miesto ponuky: %s", item->city);
    printf("ulica: %s", item->address);
    printf("rozloha v m2: %d\n", item->area);
    printf("cena: %d\n", item->price);
    printf("popis: %s", item->description);
}

/**
 * Pretty prints the whole linked list
 *
 * @param list first item in linked list
 */
void print_items(LISTITEM *list) {
    int order_number = 0;
    
    // Traversing the list till the last element and printing details
    LISTITEM *act = list;
    while (act != NULL) {
        print_single_item(act, &order_number);
        act = act->next;
    }
}

/**
 * Gets position, member values and inserts new item to desired position in list
 * while moving item on the position to pos+1
 *
 * @param list the beginning of list
 */
void insert_item_to_index(LISTITEM **list) {
    int pos;
    if (scanf(" %d", &pos) == 1 && pos > 0) {
        
        // cleaning the buffer
        // scanf leaves trailing newline after reading
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        LISTITEM *act = *list;
        
        // Traversing the whole linked list until given position or end of list
        for (int i = 1; i < pos - 1; i++) {
            if (act->next == NULL) break;
            act = act->next;
        }
        
        // Create the list if it is NULL
        if (!act) {
            *list = (LISTITEM *) malloc(sizeof(LISTITEM));
            read_item(list, stdin);
            return;
        }
        
        // Different behaviour if desired position is first item
        if (pos == 1) {
            act = *list;
            *list = (LISTITEM *) malloc(sizeof(LISTITEM));
            read_item(list, stdin);
            (*list)->next = act;
            act = NULL;
            free(act);
        }
            
            // If position > 1 create new item, and move item on its position to p+1
        else {
            LISTITEM *temp = act->next;
            act->next = (LISTITEM *) malloc(sizeof(LISTITEM));
            act = act->next;
            read_item(&act, stdin);
            act->next = temp;
        }
    }
}

/**
 * Removes item which contains given substring
 * of a 'city' member from the linked list. (Case insensitive)
 *
 * @param list first item in a list
 */
void remove_item_by_substr(LISTITEM **list) {
    char *substr = (char *) malloc(MAX_LINE_LENGTH);
    
    if ((scanf("%s", substr) == 1)) {
        if (*list == NULL) return;
        
        // Number of deleted items in this run
        int items = 0;
        
        LISTITEM *prev = NULL;
        LISTITEM *act = *list;
        
        while (act != NULL) {
            if (strstr(strlwr(act->city), strlwr(substr)) != NULL) {
                LISTITEM *temp;
                
                if (prev == NULL) {
                    temp = (*list)->next;
                    free(*list);
                    *list = temp;
                    act = *list;
                }
                else {
                    prev->next = act->next;
                    free(act);
                    act = prev->next;
                }
                
                items++;
            }
            else {
                prev = act;
                act = act->next;
            }
        }
        printf("Vymazalo sa %d zaznamov\n", items);
    }
}

/**
 * Prints list items which price is lesser than or equal to given price
 *
 * @param list first item in a list
 */
void search_item_by_price(LISTITEM *list) {
    int price;
    if (scanf(" %d", &price) == 1) {
        
        if (list == NULL) return;
        LISTITEM *act = list;
        int items = 0;
        
        while (act != NULL) {
            if (act->price <= price) {
                print_single_item(act, &items);
            }
            act = act->next;
        }
        if (!items) printf("V ponuke su len reality s vyssou cenou\n");
    }
}

/**
 * Searches for linked list item by a city (case insensitive substring)
 * Gets updated item from the user
 * and replaces all search results with the updated item
 *
 * @param list first item in a list
 */
void update_item_by_city(LISTITEM **list) {
    
    char *city = (char *) malloc(MAX_LINE_LENGTH);
    if (*list == NULL) return;
    
    if ((scanf("%s", city) == 1)) {
        
        // clean the buffer
        // scanf leaves trailing newline after reading
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        // Get updated item members
        LISTITEM *updated = (LISTITEM *) malloc(sizeof(LISTITEM));
        read_item(&updated, stdin);
        int items = 0;
        
        LISTITEM *act = *list;
        while (act != NULL) {
            if ((strstr(strlwr(act->city), strlwr(city)) != NULL)) {
                // If matches, copies the updated item members to the current search result
                cpy_item(&act, updated);
                items++;
            }
            act = act->next;
        }
        
        free_item(&updated, 1);
        if (items)
            printf("Aktualizovalo sa %d zaznamov\n", items);
    }
}

int open_file(FILE **f) {
    return (*f = fopen("../resources/reality.txt", "r")) != NULL;
}

/**
 * Load the records from the file, parse it and create new linked list
 *
 * @param list first item in a list
 */
void load_file(LISTITEM **list) {
    
    FILE *f;
    if (!open_file(&f)) {
        printf("Zaznamy neboli nacitane\n");
        return;
    }
    
    // Number of items in the list
    int items = 0;
    
    char *line = (char *) malloc(MAX_LINE_LENGTH);
    
    while (fgets(line, MAX_LINE_LENGTH, f) != NULL) {
        if (line[0] == '&') {
            items++;
            
            // Different behaviour for the first element in the list
            if (*list == NULL) {
                *list = (LISTITEM *) malloc(sizeof(LISTITEM));
                read_item(list, f);
                continue;
            }
            
            // Traversing the list till the last element
            LISTITEM *act = *list;
            while (act->next != NULL) {
                act = act->next;
            }
            
            // Appending the new element
            act->next = (LISTITEM *) malloc(sizeof(LISTITEM));
            act = act->next;
            read_item(&act, f);
            
        }
    }
    free(line);
    line = NULL;
    
    printf("Nacitalo sa %d zaznamov\n", items);
    
    // Close the file
    fclose(f);
    f = NULL;
}

int main() {
    char mode;
    LISTITEM *list = NULL;
    
    while (scanf(" %c", &mode) == 1) {
        switch (mode) {
            case ('n'): {
                if (list != NULL) free_list(&list);
                load_file(&list);
                break;
            }
            case ('v'): {
                if (list != NULL) {
                    print_items(list);
                }
                break;
            }
            case ('p'): {
                insert_item_to_index(&list);
                break;
            }
            case ('z'): {
                remove_item_by_substr(&list);
                break;
            }
            case ('h'): {
                search_item_by_price(list);
                break;
            }
            case ('a'): {
                update_item_by_city(&list);
                break;
            }
            case ('k'): {
                if (list != NULL) free_list(&list);
                return 0;
            }
            default: {
                break;
            }
        }
    }
}