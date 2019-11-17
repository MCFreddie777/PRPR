//
// Created by František Gič on 10/11/2019.
//

#include "date_functions.h"

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

