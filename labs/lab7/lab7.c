#include <stdio.h>
#include <string.h>
#define MAX_COUNTIES 100
#define MAX_CHARACTERS 499
typedef struct County{
    char    *name;
    char    *seat;
    char    *since;
    char    *description;
    char    *population;

    

}County_t; 
void sortCounties(County_t counties[]){

    // sort counties alphabetically, comparing the unicode values of the first letter from least (A) to greatest (Z)
    int smallest = 0;
    int sorted = 0; 
    County_t temp;
    char* smallestString;
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

int main(int argc, const char* argv[]){
    FILE *input = fopen("/public/labs/lab7/counties1.txt","r");

    if(input == NULL){
        printf("Failed to open input file!\n");

        return -1;
    }
    
    char lines[MAX_COUNTIES][MAX_CHARACTERS];

    for(int i = 0; i < MAX_COUNTIES; i++){
        fgets(lines[i],MAX_CHARACTERS,input);
    }

    County_t counties[MAX_COUNTIES];

    for(int i = 0; i < MAX_COUNTIES; i++){
        counties[i] = (County_t){"\0","\0","\0","\0","\0"};
        counties[i].name =  strtok(lines[i],"|");
        counties[i].seat = strtok(NULL,"|");
        counties[i].since = strtok(NULL,"|");
        counties[i].description = strtok(NULL,"|");
        counties[i].population = strtok(NULL,"|");
    }
    sortCounties(counties);
    FILE *output = fopen("outdata_strings.txt","w");
    
    for(int i = 0; i < MAX_COUNTIES; i++){
        if(counties[i].name != NULL && counties[i].population != NULL && counties[i].seat != NULL)
        fprintf(output,"%s has population %s and seat %s\n",counties[i].name,counties[i].population,counties[i].seat);
    }
    fclose(input);
    fclose(output);
    return 0;
}
