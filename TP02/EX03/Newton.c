#include <stdio.h>
#include <stdlib.h>

float Newton(float (*f)(float), float (*g)(float), float alpha, int n)
{
    int i = 0;
    while(i < n)
    {
        alpha = alpha - f(alpha) / g(alpha);
        i++;
    }
    return alpha;
}
float f(float x)
{
    x = x*x - 2;
    return x;
}
float g(float y)
{
    y = 2 * y;
    return y;
}
int main(int argc, int* argv[])
{
    float (*ptr)(float);
    float (*ptr_1)(float);
    ptr = f;
    ptr_1 = g;
    float alpha = Newton(ptr, ptr_1, 3, 10);
    printf("%f", alpha);
    return 0; 
}