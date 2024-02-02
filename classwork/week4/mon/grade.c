#include <stdio.h>

void printPointsToConsole(char grade);

int main (int argc, char* argv[]){

    printf("Enter the grade you got: ");
    char grade = (char)0; 
    scanf("%c",&grade);

    printPointsToConsole(grade);

    
    return 0; 
}


void printPointsToConsole(char grade){
    int numPoints = -1; 
    switch(grade){
        case 'a':
        case 'A':
        
        numPoints = 93;
        break; 
        
        case 'b':
        case 'B':
        
        numPoints = 83; 
        break;
        
        case 'c':
        case 'C':
        
        numPoints = 73;
        break; 

        case 'd':
        case 'D':
        numPoints = 63; 
        break; 

        default: 
        printf("You earned an unknown number of points in the class.\n");
        return; 
    }
    printf("You earned at least %d points in the class.\n",numPoints);
    return; 
}

