#include <stdio.h>


int main(int argc, const char* argv[]){

    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");

    double temp = 0;

    while(fscanf(input,"%lf",&temp) != EOF){
        fprintf(output,"%.2lf\n",temp); 
    }
    fclose(input);
    fclose(output); 
    return 0;
}
