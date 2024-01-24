#include <stdio.h>
#define MIN_TO_HOUR 0.016667 //(1/60)
int main(int argc, char const *argv[]){
    printf("Hours and minutes since power outage? (e.g., 2 30 for 2 hours, 30 minutes)");
    int hour, minute;
    scanf("%i %i",&hour, &minute);
    double totalTime = (double)hour + (double)minute * (double)MIN_TO_HOUR;

    double temperature = (3*(totalTime*totalTime))/(totalTime + 1.0) - 10.0; 

    printf("Estimated current temperature: %.2f degrees Celsius",temperature);
    return 0;
}
