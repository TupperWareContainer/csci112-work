#include <stdio.h>

int main(int argv, char* argc[]){
   
    int arr[3][5];

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &arr[0][0], &arr[0][1],&arr[0][2],&arr[0][3],&arr[0][4]                                                        , &arr[1][0], &arr[1][1],&arr[1][2],&arr[1][3],&arr[1][4]                                                        , &arr[2][0], &arr[2][1],&arr[2][2],&arr[2][3],&arr[2][4]         );
    int sum = 0; 
    for(int i = 0; i < 3; i++){
        sum = 0; 
        
        for(int j = 0; j < 5; j++){
            sum += arr[i][j];
        }
        printf("Row %d has total %d.\n", i, sum);

    }

    return 0;

}
