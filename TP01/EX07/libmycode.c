#include <stdio.h>
#include "mycode.h"

void print_bits(int number)
{
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
void check_msb(int num)
{
    (num >> 31) ? printf("The most significant bit is set.\n") : printf("The most significant bit is not set");
}
void print_nth_byte(int n, int m)
{
        int j = 0;
        if(n == 4)
        {
            for(j = 31; j >= 24; j--)
                (m & (1 << j)) ? printf("1 ") : printf("0 ");
            printf("\n");
        }
        if(n == 1)
        {
            int l = m << 24 ;
            for(j = 31; j >= 24; j--)
                (l & (1 << j)) ? printf("1 ") : printf("0 ");
            printf("\n");
        }
        if(n == 2)
        {
            int l = m << 16 ;
            for(j = 31; j >= 24; j--)
                (l & (1 << j)) ? printf("1 ") : printf("0 ");
            printf("\n");
        }
        if(n == 3)
        {
            int l = m << 8 ;
            for(j = 31; j >= 24; j--)
                (l & (1 << j)) ? printf("1 ") : printf("0 ");
            printf("\n");
        }
}
