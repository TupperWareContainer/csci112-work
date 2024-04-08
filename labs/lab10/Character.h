#ifndef CHARACTER_H
#define CHARACTER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct Character{
    char*   name;
    int     xp;
    int     hp;
    bool    dead;
}Character;

Character* createCharacter(char* name, char* xp, char* hp, int nameSize);

void destroyCharacter(Character* character);

void printResults(Character* a, Character* b);

void fight(Character* a, Character* b);


#endif //CHARACTER_H
