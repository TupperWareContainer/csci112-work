#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_COUNTIES 100
#define MAX_CHARACTERS 499
typedef struct County{
    char    *name;
    char    *seat;
    int     population;
}County; 
void sortCounties(County counties[]){

    // sort counties alphabetically, comparing the unicode values of the first letter from least (A) to greatest (Z)
    int smallest = 0;
    int sorted = 0; 
    County temp;
    char* smallestString = counties[0].name;
    char* currentString;

    while(sorted < MAX_COUNTIES){
        for(int i = sorted; i < MAX_COUNTIES; i++){
            if(counties[i].name == NULL || smallestString == NULL) continue; //if nullptr, ignore
            currentString = counties[i].name; 
            if(strcmp(smallestString, currentString) > 0){
                smallestString = counties[i].name;
                smallest = i;
            }
        }
        temp = counties[smallest];
        counties[smallest] = counties[sorted];
        counties[sorted] = temp;
        sorted++; 
        smallest = sorted;
        smallestString = counties[sorted].name; 
    }
}
County add_county(char* name, char* seat, int pop){
    County out = (County){"\0","\0",0};
    out.name = name;
    out.seat = seat;
    out.population = pop;
    return out;

}



int parseCountiesToArray(County outArray[]){

    FILE *input = fopen("/public/labs/lab8/counties1.txt","r");

    if(input == NULL){
        printf("Failed to open input file!\n");

        return -1;
    }
    
    char lines[MAX_COUNTIES][MAX_CHARACTERS];

    for(int i = 0; i < MAX_COUNTIES; i++){
        fgets(lines[i],MAX_CHARACTERS,input);
    }


    for(int i = 0; i < MAX_COUNTIES; i++){
        char* name = strtok(lines[i],"|");
        char* seat = strtok(NULL,"|");
        strtok(NULL,"|");
        strtok(NULL,"|");
        char* population = strtok(NULL,"|");
        int popNum = 0; 
        if(population != NULL)  sscanf(population, "%d",&(popNum));
        outArray[i] = add_county(name, seat,popNum);
    }
    sortCounties(outArray);
    fclose(input);
    return 0;
}
void prompt(){
    printf("~~~Welcome to the county database!\n");
    printf("~~~To search for a county by seat, press 1.\n");
    printf("~~~To search for counties within a population range, press 2.\n");
    printf("~~~To exit, press any other key.\n");
}

void searchDatabaseBySeat(const County database[], const char* seat, int buffer){
    // database is sorted by county name and not seat, meaning we have to use linear search
    for(int i = 0; i < MAX_COUNTIES; i++){
        if(database[i].seat == NULL) continue;
        else if(strncmp(database[i].seat, seat, buffer) == 0){
            printf("%s has seat %s\n",database[i].name, seat);
            return;
        }
    }
}

void getCountiesByPopRange(int minPop, int maxPop, const County database[]){
    int n = 0;
    for(int i = 0; i < MAX_COUNTIES; i++){
        if(database[i].name == NULL || database[i].seat == NULL) continue;
        else if(database[i].population >= minPop && database[i].population <= maxPop){
            if(n == 0){ 
                n++;
                printf("The counties with populations between 2000 and 0 are:\n");
            }
            printf("%s, pop. %d\n",database[i].name, database[i].population);
        }

    }

}

int main(int argc, const char* argv[]){
    County counties[MAX_COUNTIES]; 
    if(parseCountiesToArray(counties) < 0) return -1;
    bool quit = false;
    int input = 0;
    while (!quit){
        prompt();
        scanf("%d",&input);

        switch(input){
            case 1:
                char seat[20];
                printf("Enter a county seat to search for: ");
                scanf("%s",seat);
                searchDatabaseBySeat(counties, seat, 20);
            break; 
            case 2:
                int max = 0, min = 0;
                printf("Enter an upper bound for the population (inclusive): ");
                scanf("%d",&max);
                printf("Enter a lower bound for the population (inclusive): ");
                scanf("%d",&min);
                getCountiesByPopRange(min,max,counties);
            break;
            default: 
                quit = true;
            break;
        }
        input = -1; 

    }
    


    return 0;
}
