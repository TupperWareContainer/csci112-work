#ifndef TEAM_H
#define TEAM_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Person
{
    char* name; 
}Person;

typedef struct Team
{
    Person** arr; 
    int size;
    int capacity;
}Team;

void initialize_team(Team* team, int capacity);

Person* create_new_person(char* name);

void insert_person_at_back(Team* team, Person* person);

void print_team(Team* team);

void delete_person_at_back(Team* team);

void decommission_team(Team* team);


#endif //TEAM_H
