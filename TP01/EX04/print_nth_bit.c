#include <stdio.h>
#include <stdlib.h>
#include 'print_nth_bit.h'

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
