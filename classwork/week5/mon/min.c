#include <stdio.h>


int main(int argv, char* argc[]){

    char c1 = (char)0; 
    char c2 = (char)0; 

    printf("Enter two characters: ");

    int eof = scanf("%c %c",&c1, &c2);

    if(!eof){ 
        printf("Characters not recognized!\n");
        return 1; 
    }
    char min = (c1 < c2) ? c1 : c2; 

    printf("Min is %c\n",min);
    return 0; 

}
