#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char* argv[]){
 
    char input[255];
    double num; 
    bool valid = false; 
    do{
        printf("Enter a number between 0 and 100: (decimals okay): ");
        scanf("%s",input);

        num = atof(input);

        if(num == 0.0){
            for(int i = 0; i < 255; i++){
                if(input[i] == '0'){
                    valid = true; 
                    break;
                }
    
            }
            if(valid) break;
            else{
                printf("You didn't enter a number\n");
                return 0;  
            }

        }
        
    
    }while(num > 100 || num < 0); 
    
    printf("You entered %.2lf\n",num);

    return 0;

}
