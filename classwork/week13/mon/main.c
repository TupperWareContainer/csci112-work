#include <stdio.h>

int main(void) {
    int intarray[5] = {10,20,30,40,50};
   // int *pointer = &intarray[2];

    // Array of 3 pointers
    int *parray[3];

    // TODO:
    // Copy last three addresses of intarray into parray
    // Use parray and pointer
    int i;
    for (i = 0; i < 3; i++) {
        // you add a line here
        parray[i] = &intarray[i+2];
    }

    // Test code (do not edit)
    for (i = 0; i < 3; i++) {
        printf("%d\n", parray[i] == &intarray[i+2]);
    }

    return 0;
}
