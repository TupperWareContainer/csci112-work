#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define NUM_SUBSTANCES 5


typedef struct Substance{
    char    name[32];
    double  temperature;
}Substance_t; 


Substance_t substances[] = {
                            (Substance_t){"water",100.0}, 
                            (Substance_t){"mercury",375.0},
                            (Substance_t){"copper",1187.0},
                            (Substance_t){"silver",2193.0},
                            (Substance_t){"gold",2660.0}
                           }; 
/// Determines whether data is within x percent of ref
/// Returns 1 if true, 0 if false
int within_x_percent(double ref, double data, double x){
    x /= 100.0; 
    double pDiff = ref * x; 
    double dDiff = fabs(ref - data);

    if(dDiff <= pDiff) return 1; 
    else return 0; 
    
     
}
int filterInput(double temp, double pError){
    int withinPercent = 0; 
    for(int i = 0; i <NUM_SUBSTANCES; i++){
        withinPercent = within_x_percent(substances[i].temperature,temp,pError);
        
        if(withinPercent == 1){
            printf("Substance is %s\n", substances[i].name);
            return 1; 
        }
    } 
    printf("Substance unknown\n");
    return 0; 
}


int main(int argc, char*  argv[]){
    double temperature = 0.012359; 
    double pError = 0.001235;

    
    printf("Observed boiling point (in deg. C)? ");
    scanf("%lf",&temperature);
    if(temperature == 0.012359){
        printf("Error: bad input\n");
        return 0; 
    }
    printf("You entered %.2lf\n",temperature);
    printf("Custom error percent? n for no (5%% default), y for yes: ");
    char input = (char)0; 

    scanf(" %c",&input);
    if(input == (char)0){ 
        printf("Error: bad input\n");
        return 0; 
    }
    else if(input == 'y' || input == 'Y'){
        printf("Enter error percent: ");

        scanf("%lf",&pError);

        if(pError == 0.001235){
            printf("Error: bad input\n");
            return 0;
        }
        printf("You entered %.2lf percent\n",pError);
        filterInput(temperature, pError);
    }
    else if (input == 'n' || input == 'N'){
        pError = 5.0; 
        filterInput(temperature, pError);
        return 0; 
    }
    else{
        printf("Error: bad input\n");
        return 0;
    }

    
    

    return 0;
}


