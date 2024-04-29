#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Function to print a number in binary
void print_binary(unsigned int num) {
    // TODO: implement this function so that it prints all 32 bits
    // separate each group of 4 bits with a space
    
    int value = 0;
    
    char* outString = calloc(32, sizeof(char)); 
    
    for(int i = 0; i <32; i++)
    {
        value = (num & (1<<i)) != 0;
        outString[i] = value + '0';
    }
    int numSpaces = 0;    
    for(int i = 31; i >=0; i--)
    {
        if(numSpaces == 4)
        {
            printf(" ");
            numSpaces = 0;
        }

        printf("%c",outString[i]);
        numSpaces++;
    }
    free(outString); 
    printf("\n");
}

int main(void) {
    // should print 0000 0000 0000 0000 0000 0000 0011 0010 
    print_binary(50);
   // should print 0000 0000 0000 0011 1001 0111 1010 1000 
    print_binary(235432);
    // should print 0000 0001 0011 0001 0000 1111 0110 0111
    print_binary(19992423);
}
