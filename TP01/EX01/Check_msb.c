#include <stdio.h>
#include <stdlib.h>

void check_msb(int num)
{
    (num >> 31) ? printf("The most significant bit is set.\n") : printf("The most significant bit is not set");
}
int main (int argc, char *argv[])
{
    check_msb(2);
}