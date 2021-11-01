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
float Dichotomie2(float (*f)(float), float a, float b, float e)
{
    int n = (log((b - a)) /(e * log(2))) + 1;
    float alpha = Dichotomie(f, a, b, n);
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
    float (*ptr_1)(float);
    ptr = g;
    ptr_1 = g;
    float alpha = Dichotomie(ptr, 1, 20, 10);
    float alpha2 = 0;
    alpha2 = Dichotomie2(ptr_1, 1, 20, 0.000000000000010);
    printf("%f\n",alpha);
    printf("%f\n", alpha2);
    return 0;
}