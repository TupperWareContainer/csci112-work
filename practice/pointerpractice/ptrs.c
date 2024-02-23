#include <stdio.h>

int main(int argc, const char* argv[]){

    int var = 10; 

    int addr =(int)&var; 

    printf("var.value = %d\nvar.addr = %d\n",var,addr);

    int *ptr = &var;

    printf("Created pointer that points to var\n");

    *ptr = 24; 

    printf("Modified pointer value using deference\nvar.value = %d\n",var);

    return 0;

}
