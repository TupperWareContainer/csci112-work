#include "Character.h"

Character* createCharacter(char* name, char* xp, char* hp, int nameSize){
    Character* out = malloc(sizeof(Character));
    out->name = calloc(nameSize,sizeof(char));

    strncpy(out->name, name,nameSize);
   
    sscanf(xp,"%d",&out->xp);

    sscanf(hp,"%d",&out->hp);
    
    out->dead = false;

    return out;
}

void destroyCharacter(Character* character){
    free(character->name);

    free(character);

    character = NULL;

}
void fight(Character* a, Character* b){
    printf("### LET'S FIGHT ###\n");
    printf("%s (%d XP, %d HP) vs. %s (%d XP, %d HP)\n",a->name, a->xp, a->hp, b->name, b->xp, b->hp);

    if(a->xp == b->xp){
        printf("It's a tie!\n");
        printResults(a,b);
        return;
    }
    Character* winner = NULL; 
    Character* loser = NULL;
    if(a->xp > b->xp){
        winner = a; 
        loser = b;
    }
    else{
        winner = b; 
        loser = a;
    }
    
    int diff = winner->xp - loser->xp; 

    loser->hp -= diff;

    int xpGain = (int)round(log10((double)winner->xp));

    winner->xp += xpGain;
    
    loser->xp = (int)round((double)loser->xp * 1.5);


    printf("%s deals %d damage to %s\n",winner->name, diff, loser->name);
    
    if(loser->hp <= 0){
        loser->dead = true;
        size_t len = strlen(loser->name) + strlen(" (deceased)");
        char* temp = calloc(strlen(loser->name),sizeof(char));
        strncpy(temp, loser->name,strlen(loser->name));
        free(loser->name);
        loser->name = calloc(len,sizeof(char));

        sprintf(loser->name, "%s%s",temp," (deceased)");

        free(temp);
    }
    printResults(a,b);
}

void printResults(Character* a, Character* b){

    printf("\nResult is:\n");
    printf("%s (%d XP, %d HP)\n%s (%d XP, %d HP)\n",a->name, a->xp, a->hp, b->name, b->xp, b->hp);
}
