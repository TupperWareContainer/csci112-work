#include <stdio.h>
#include <stdlib.h>

void printHex(char* bin);

void printBinary(unsigned int num)
{
    char* out = calloc(32, sizeof(char));
    int value = 0;
    for(int i = 0; i < 32; i++)
    {
        value = (num & (1<<i)) != 0; 

        out[i] = value + '0'; 
    }

    int spaces = 0;
    for(int i = 31; i >=0; i--)
    {
        if(spaces == 4)
        {
            printf(" ");
            spaces = 0;
        }    

        printf("%c",out[i]);
        spaces++;

    }
    printf("\n");
    
    printHex(out);
    
    free(out);
}

char toHex(unsigned int num)
{
    if(num < 10) return num + '0';
    else return (num - 10) + 'a';
}

void printHex(char* bin)
{
    int value = 0;

    int halfByte = 0;

    int bitsRead = 0;

    for(int i = 31; i >= 0; i--)
    {
        value = 0;
        value = bin[i] - '0';
        halfByte = halfByte << 1;
        halfByte |= value;
        bitsRead++; 

        if(bitsRead >= 4)
        {
            bitsRead = 0;
            printf("%-5c",toHex(halfByte));
            halfByte = 0;
        }
    }
    printf("\n");
}



int main(int argc, const char* argv[])
{
    printf("Enter two unsigned integers: ");
    unsigned int n1 = 0, n2 = 0;

    scanf("%u %u",&n1, &n2);
    printf("\nBinary & hex representation:\n");

    printf("Number 1:\n");
    
    printBinary(n1);

    printf("Number 2:\n");
    
    printBinary(n2);
    
    unsigned int bitwiseAnd = (n1 & n2);

    printf("\nBitwise AND of Number 1 and Number 2: %u\n",bitwiseAnd);
    
    printf("Binary & hex representation:\n");
    
    printBinary(bitwiseAnd);

    unsigned int bitwiseOr = (n1 | n2);

    printf("\nBitwise OR: %u\n",bitwiseOr);

    printf("Binary & hex representation:\n");
    
    printBinary(bitwiseOr);

    unsigned int bitwiseXOR = (n1^n2);

    printf("\nBitwise XOR: %u\n",bitwiseXOR);

    printf("Binary & hex representation:\n");

    printBinary(bitwiseXOR);
    
    unsigned int bitwiseNOTn1 = ~n1; 

    unsigned int bitwiseNOTn2 = ~n2;

    printf("\nBitwise NOT on first number: %u\n",bitwiseNOTn1);

    printf("Binary & hex representation:\n");
    
    printBinary(bitwiseNOTn1);

    printf("\nBitwise NOT on second number: %u\n",bitwiseNOTn2);

    printf("Binary & hex representation:\n");

    printBinary(bitwiseNOTn2);

    printf("\nEnter a bit position to modify: ");

    unsigned int position = 0; 
    
    scanf("%u",&position);

    int choice = 0;

    printf("Set, clear, or toggle (1/2/3)? ");

    scanf("%d",&choice);

    printf("Original number: %u\n",n1);
    printBinary(n1);
    switch(choice)
    {
        default:
        case 1:
            n1 = n1 | (1<<position);
        break;
        case 2:
           n1 = n1 & ~(1 << position); 
        break;
        case 3:
            n1 = n1 ^ (1 << position);
        break;
    }
    printf("Modified number: %u\n",n1);
    printf("Binary & hex representation:\n");
    printBinary(n1);

    return 0;
}
