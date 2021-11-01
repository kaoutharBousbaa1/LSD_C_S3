#include <stdio.h>
#include <stdlib.h>
#include 'header.h'

int main(int argc, char *argv[])
{
    int *x;
    x = nelem_table(20);
    print_table(x, 20);
}