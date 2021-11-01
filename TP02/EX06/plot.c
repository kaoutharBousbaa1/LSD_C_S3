#include <stdio.h>
#include <stdlib.h>

float *Newton(float (*f)(float), float (*g)(float), float alpha, int n)
{
    int i = 0;
    float *arr = (float*)malloc(sizeof(float) * n);
    while(i < n)
    {
        alpha = alpha - f(alpha) / g(alpha);
        arr[i] = alpha;
        i++;
    }
    return arr;
}
float f(float x)
{
    x = x*x*x - x - 3;
    return x;
}
float g(float y)
{
    y = 3*y*y - 1;
    return y;
}
void print_arr(float* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%f   ", arr[i]);
    }
}
int main(int argc, int* argv[])
{
    float (*ptr)(float);
    float (*ptr_1)(float);
    ptr = f;
    ptr_1 = g;
    float *alpha = Newton(ptr, ptr_1, 3, 10);
    print_arr(alpha, 10);
    int x[10];
    for(int i = 0; i < 10; i++)
    {
        x[i] = i+1;
    }
    FILE *gnuplot = fopen("gnuplot", "w");
    if(!gnuplot)
    {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 10; i++)
        fprintf(gnuplot, "%d %d\n", x[i], alpha[i]);
    fprintf(gnuplot, "e\n");
    fprintf(stdout, "Click Ctrl+d to quit...\n");
    fflush(gnuplot);
    getchar();
    pclose(gnuplot);
    exit(EXIT_SUCCESS);
    return 0; 
}