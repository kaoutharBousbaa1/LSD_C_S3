#include <stdio.h>
#include <stdlib.h>

float **create_m(int n)
{
    float **A = (float**)malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++)
    {
        A[i] = (float*)malloc(sizeof(float) * n);
        for(int j = 0; j < n; j++)
        {   
            A[i][j] = i;
            printf("%f\n",A[i][j]);
        }
    }
    return A;
}
float **sum_m(float **A, float **B, int n)
{
    float **C;
    C = (float**)malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++ )
    {
        C[i] = (float*)malloc(sizeof(float) * n);
        for(int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
float **mult_m(float **A, float **B, int n)
{
    float **C;
    C = (float**)malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++)
    {
        C[i] = (float*)malloc(sizeof(float) * n);
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < n; k++)
                C[i][j] += A[i][j] *  B[k][j];
        }
    }
    return C;
    
}
void print_m(float **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }
}
float ** trans_m(float **A, int n)
{
    float **C;
    C = (float**)malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++)
    {
        C[i] = (float*)malloc(sizeof(float) * n);
        for(int j = 0; j < n; j++)
        {
            C[i][j] = A[j][i];
        }
    }
    return C;
}
float **dia_n(float **A, int n)
{
    float **C;
    C = (float**)malloc(sizeof(float*) * n);
    for(int i = 0; i < n; i++)
    {
        C[i] = (float*)malloc(sizeof(float) * n);
        for(int j = 0; j < n; j++)
        {
            if(i != j)
                C[i][j] =0;
            else
                C[i][j] = A[i][j];
        }
        C[i][n-1-i] = A[i][n-1-i];
    }
    return C;
}
int main(int argc, int *argv[])
{
    float **A = NULL;
    A = create_m(5);
    print_m(A, 5);
    printf("\n");
    float **B = NULL;
    B = create_m(5);
    print_m(B, 5);
    printf("\n");
    float **C = NULL;
    C = dia_n(A, 5);
    print_m(C, 5);
    printf("\n");
    return 0;
}