#include "Character.h"
int main(int argc, const char* argv[]){
    char* lines[6];

    if(argc < 7){
        printf("Please enter the stats for at least two fighters\n");
        return 0;
    }

    for(int i = 0; i < 6; i++){
        size_t len = strlen(argv[i+1]) + 1;
        lines[i] = calloc(len,sizeof(char));
        lines[i] = strncpy(lines[i],argv[i+1],len);
    //    printf("%s\n",lines[i]);
    }
    Character* c1 = createCharacter(lines[0],lines[1],lines[2],strlen(lines[0]));
    Character* c2 = createCharacter(lines[3],lines[4],lines[5],strlen(lines[3]));

    for(int i = 0; i < 6; i++){
        free(lines[i]);
        lines[i] = NULL;
    }
    //printf("%s (%d XP, %d HP)\n",c1->name, c1->xp, c1->hp); 
    //printf("%s (%d XP, %d HP)\n",c2->name, c2->xp, c2->hp);

    fight(c1,c2);

    destroyCharacter(c1);
    destroyCharacter(c2);

    return 0;
}
