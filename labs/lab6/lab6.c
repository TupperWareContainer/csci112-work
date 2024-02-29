#include <stdio.h> 
#include <limits.h>
void printArray(const double array[], int size){
    for(int i = 0; i < size; i++){
        printf("%.2lf ",array[i]);
    }
    printf("\n");

}

void writeToFile(const char* fileName, const double* array, int arraySize){
    FILE *output = fopen(fileName,"w");
    if(output == NULL){
        printf("ERROR : FAILED TO OPEN FILE\n");
        return;
    }
    for(int i = 0; i <arraySize; i++){
        fprintf(output,"%.2lf\n",array[i]);
    }

    fclose(output);


}


int main(int argv, const char* argc[]){

    

    FILE *input = fopen("/public/labs/lab6/numbers.txt","r");

    if(input == NULL){
        printf("ERROR : FAILED TO OPEN INPUT FILE\n");
        return -1; 
    }
    double array[100];
    int endIndex = 0; 

    double num = 0.0;

    while(fscanf(input,"%lf",&num) != EOF && endIndex < 100){
        array[endIndex] = num;
        endIndex++;
    }
    fclose(input);
    printf("Before sorting, arr of numbers is\n");
    
    int size = endIndex < 100 ? endIndex: 100;
    
    printArray(array,size);

    printf("Now performing selection sort:\n");
   // printArray(array,size);
    int sorted = 0; 
    double min = INT_MAX;
    int minIndex = 0;
    while(sorted < size){
        if(sorted > 0) printArray(array,size);
        for(int i = sorted; i < size; i++){
            if(array[i] < min){
                min = array[i];
                minIndex = i;
            }
        }
        array[minIndex] = array[sorted];
        array[sorted] = min;
        min = INT_MAX;
        sorted++;
    }
    writeToFile("outdata.txt",array,size); 
    return 0;

}
