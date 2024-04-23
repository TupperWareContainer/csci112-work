#include "team.h"

void initialize_team(Team* team, int capacity)
{
    if(team == NULL){
        team = malloc(sizeof(Team));
    }
    team->size = 0;
    team->capacity = capacity;
    team->arr = (Person**)calloc(capacity,sizeof(Person));

    if(team->arr == NULL){
        printf("Failed to allocate memory for person array!\n");
        free(team);
    }
}

Person* create_new_person(char* name)
{
    Person* person = malloc(sizeof(person));

    if(person == NULL){
        printf("Failed to allocate memory for person struct!\n");
        return NULL;
    }

    int length = strlen(name);
    
    person->name = calloc(length, sizeof(char));

    if(person->name == NULL){
        printf("Failed to allocate memory for name field of person struct!\n");
        free(person);
        return NULL;
    }

    strncpy(person->name, name, length);

    return person;
}

void insert_person_at_back(Team* team, Person* person)
{
    if(team->size < team->capacity){
        team->arr[team->size] = person;
        team->size++;
    }
    else{
        Person** temp = team->arr;
   //     printf("%lu\n",sizeof(temp));
        team->arr = realloc(team->arr, team->capacity * 2 * sizeof(Person));
        if(team->arr == NULL)
        {
            printf("Failed to reallocate memory for team!\n");
            team->arr = temp;
            
            return;
        }
        team->capacity *= 2;
        team->arr[team->size] = person; 
        team->size++; 
    }
}

void print_team(Team* team)
{
    printf("[");
    for(int i = 0; i < team->size; i++)
    {
        if(i != 0) printf(", ");
        printf("%s",team->arr[i]->name);
    }
    printf("]\n");
    printf("Capacity is %d and current size is %d\n",team->capacity, team->size);

}

void delete_person_at_back(Team* team)
{
    if(team->size == 0)return;
    Person* ptr = team->arr[team->size - 1];
    team->arr[team->size - 1] = NULL;

    free(ptr->name);
    free(ptr);

    ptr = NULL;

    team->size--;
    team->size = (0 > team->size) ? 0 : team->size;

    if(team->size <= team->capacity * 0.5){
        Person** temp = team->arr;
        int newSize = ((team->capacity * 0.5) > 0) ? team->capacity * 0.5 : 1;
        team->arr = realloc(team->arr, newSize * sizeof(Person));
        if(team->arr == NULL && temp != NULL)
        {
            //printf("Failed to shrink dynamic team array, falling back to previous ptr\n");
            team->arr = temp;
            newSize = team->capacity;
        }
        team->capacity = newSize;
    }
}

void decommission_team(Team* team)
{
    for(int i = 0; i < team->capacity; i++)
    {
        if(team->arr[i] != NULL){
            Person* ptr = team->arr[i];
            char* cptr = ptr->name;
            free(cptr);
             
            free(ptr);
            team->arr[i] = NULL;
        }
    }
    free(team->arr);
}
