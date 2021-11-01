#include <stdio.h>
#include <stdlib.h>
#include 'header.h'

int *nelem_table(int n)
{
    int *y;
    int i = 0;
    int j = 0;
    y = (int*)malloc(sizeof(int) * n);
    while(i < n)
    {
        y[i] = j;
        i++;
        j++;
    }
    return (y);
}
void print_table(int *table, int n)
{
    int i;
    int *temp;
    temp = nelem_table(n);
    for(i = 0; i < n; i++)
    {
        printf("%d  ", *temp);
        temp++;
    }
}
