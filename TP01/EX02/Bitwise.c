#include <stdio.h>
#include <stdlib.h>
#include 'Bitwise.h'

void print_bits(int number){
    int i;
    i = 31;
    while(i >= 1)
    {
        (number & (1 << i)) ? printf("1 ") : printf("0 ");
        i--;
    }
    (number & (1 << i)) ? printf("1 ") : printf("0 ");
    printf("\n");
}
void check_msb(int num){
    (num >> 31) ? printf("The most significant bit is set.\n") : printf("The most significant bit is not set");
}
/*unsigned char decimalToBinary(unsigned char decimalnumber){
    unsigned char binarynumber = 0;
    char temp = 1;

    while (decimalnumber!=0)
    {
        temp = decimalnumber%2;
        decimalnumber = decimalnumber / 2;
        binarynumber = binarynumber + temp;
        temp = temp * 10;
    }
    return binarynumber;
}*/

/*void print_bits(unsigned char decimalnumber){
    unsigned char binary = decimalToBinary(decimalnumber);
    char m = (binary >> sizeof(char) * 8 - sizeof(binary));
    char* table = malloc(sizeof(char));
    for(int i = 0; i < m; i++)
    {
        table[i] = 0;
    }
    table[m+1] = binary;
}*/
/*void print_bits(unsigned char number){
    for(int i = 0; i < 8; i++)
    {
        (number >> 8 - i ) ? printf("1 ") : printf("0 ");
    }
    (number << 7) ? printf("1 ") : printf("0 ");
}*/
/*void print_bits(unsigned char number){
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (number & i) ? printf("1 ") : printf("0 ");
}*/
