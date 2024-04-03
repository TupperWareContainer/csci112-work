#ifndef COUNTY_H
#define COUNTY_H

#include <string.h>

typedef struct County{
    char    name[100];
    char    seat[100];
    int     pop;

}County;

County add_county(char* name, char* seat, int pop);


#endif // COUNTY_H
