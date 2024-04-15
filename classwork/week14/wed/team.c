#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "team.h"

void insert_person_at_back(Team* t, Person* p) {
    if(t == NULL)
    {
        printf("Team.c::insert_person_at_back() : ERROR : TEAM STRUCT IS NULL\n");
        return;
    } 
    else if(t->head == NULL){
        t->head = p; 
        return;
    }

    Person* cPtr = t->head;

    while(cPtr->next != NULL)
    {
        cPtr = cPtr->next;
    }
    cPtr->next = p; 
    return;
}
