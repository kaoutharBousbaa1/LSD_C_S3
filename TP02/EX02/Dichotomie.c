#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Dichotomie(float (*f)(float), float a, float b, int n)
{
    int i = 0;
    float alpha = 0;
    while(i < n)
    {
        alpha = (a + b) / 2;
        if(f(alpha) >= 0)
            b = alpha;
        else
            a = alpha;
        i++;
    }
    return alpha;
}
float g(float x)
{
    x =  x*x + 1;
    return x;
}
int main(int argc, int *argv[])
{
    float (*ptr)(float);
    ptr = g;
    float alpha = Dichotomie(ptr, 1, 20, 10);
    printf("%f\n",alpha);
    return 0;
}