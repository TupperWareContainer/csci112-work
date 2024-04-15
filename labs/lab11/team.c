#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "team.h"

Person *create_new_person(char *name) {
    Person* person = malloc(sizeof(Person));
    int length = strlen(name);
    person->name = calloc(length,sizeof(char));
    
    strncpy(person->name, name, length);

    person->next = NULL;

    return person;
}

void insert_person_at_front(Team *t, Person *p) {
    if(t->head == NULL) t->head = p;
    else
    {
        Person* ptr = t->head; 

        t->head = p;

        p->next = ptr;
    }
}

void print_team(Team *t) {
    Person* ptr = t->head; 

    while(ptr != NULL){
        printf("%s->",ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete_person_at_front(Team *t) {
    if(t == NULL || t->head == NULL) return;
    Person* ptr = t->head->next;
    
    free(t->head->name);
    t->head->name = NULL;
    t->head->next = NULL;
    free(t->head);

    t->head = ptr;
}

int is_empty(Team t) {
    return t.head == NULL;
}
