//
// Created by František Gič on 10/11/2019.
//

#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

#include <stdio.h>
#define DATEFORMAT "rrrrmmdd"

void parse_date(const char *string_date, int date[3]);
short at_least_year(char *date_from, char *date_to);

#endif
