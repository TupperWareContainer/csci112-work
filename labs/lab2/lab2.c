#include <stdio.h>

void getWageInfo(){
    printf("Enter hours worked on day 1: ");
    double h1 = 0.0;
    double p1 = 0.0;
    
    scanf("%lf",&h1);
    printf("Enter hourly wage on day 1: $");
    scanf("%lf",&p1);

    double h2 = 0.0; 
    double p2 = 0.0; 
 
    
    printf("Enter hours worked on day 2: ");
    scanf("%lf",&h2);
    printf("Enter hourly wage on day 2: $");
    scanf("%lf",&p2);
 
    double h3 = 0.0; 
    double p3 = 0.0; 

    printf("Enter hours worked on day 3: ");
    scanf("%lf",&h3);
    printf("Enter hourly wage on day 3: $");
    scanf("%lf",&p3);

    double total = (h1 * p1) + (h2*p2) + (h3*p3);

    printf("\nYour total pay is $%.2lf\n",total);
}
   
int main(int argc, char const *argv[]){
    getWageInfo();     


}
