#include <stdio.h>
#include <stdbool.h>
int getDayType(int temperature){
    if(temperature >= 85) return 1; 
    else if(temperature >= 60) return 2; 
    else return 3; 
}

double roundToNearestTenth(double num){

    int filter = num * 100; 
    int lastDigit = filter % 10;

    if(lastDigit >=5) filter += (10 - lastDigit); 
    else filter -= lastDigit; 

     return (double)filter/100.0; 
}


int main(int argv, char* argc[]){
    
    int h = 0, p = 0, c = 0; 
    
    bool close = false; 
    
    int num = 0;

    int funcOut = -1; 

    double  sum = 0; 

    while(!close){
        printf("Enter a high temp reading (-99 to quit)> ");

        scanf("%d",&num);
        if(num == -99){
            close = true; 
            break; 
        }
        
        sum += num; 
        funcOut = getDayType(num);

        switch(funcOut){
            case 1:
                h++; 
            break; 
            case 2:
                p++;
            break;
            case 3:
                c++;
            break;
            default:
            break;
        }
    }
    printf("H: "); 
    for(int i = 0; i < h; i++) printf("*");
    printf("\nP: ");
    for(int i = 0; i < p; i++) printf("*");
    printf("\nC: ");
    for(int i = 0; i < c; i++) printf("*");
    
    double average = sum / (double)(h+p+c);

    average = roundToNearestTenth(average);

    printf("\nAverage temperature: %.1lf\n",average);


    return 0;
}
