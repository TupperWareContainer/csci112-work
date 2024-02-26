#include <stdio.h>

int main(int argc, const char* argv[]){
    int integerSize = sizeof(int);
    int doubleSize = sizeof(double);
    int charSize = sizeof(char);

    int a[3] = {1,2,3};
    double d[3] = {1.0,2.0,3.0};
    char g[3] = {'a','b','c'};

    int *iptr = &a[0]; 
    double *dptr = &d[0]; 
    char *cptr = &g[0]; 

    printf("int size : %d\ndoubleSize: %d\ncharSize: %d\n\n",integerSize,doubleSize,charSize);

    for(int i = 0; i <3; i++){
        printf("iptr: %d\ndptr: %d\ncptr: %d\n\n",iptr,dptr,cptr); 
        printf("integer: %d\ndouble: %lf\nchar: %c\n\n",*iptr,*dptr,*cptr);
        iptr += 1; 
        dptr += 1; 
        cptr += charSize;
        printf("a[%d] is located at : %d\n\n",i,&a[i]);
    }

    return 0;

}
