#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x)
{
	double y ;
	y = sin(x); 
	return y;
}
double PolyLagrange(double *X, double x, int i)
{
	double y = X[i];
	double res = 1;
	for(int k = 0; k < sizeof(X); k++)
	{
		if(y != X[k])
			res = res * ((x - X[k])/(y - X[k]));
	}
	return res;
}
double InterLagrange(double* X, double f(double x), double x)
{
	double res = 0;
	int i;
	for(i = 0; i < sizeof(X); i++)
		res += f1(X[i])*PolyLagrange(X, x, i);
	return res;
}
int main()
{
    FILE *gnuplot1 = fopen("cor1.txt", "w");
    FILE *gnuplot2 = fopen("cor2.txt", "w");
    FILE *gnuplot3 = fopen("cor3.txt", "w");
    double tb[3];
    double tb1[3];
    double tb2[10];
    double tb3[10];
    double tb4[20];
    double tb5[20];
    double tb6[3];
    double tb7[10];
    double tb8[20];
    int i;
    for(i = 1; i < 3; i++)
	tb[i] += tb[i-1] + 2/3;
    for(i = 0; i < 3; i++)
    {
	tb1[i] = f1(tb[i]);
	tb6[i] = InterLagrange(tb, f1, i);
    }
    for(i = 0; i < 3; i++)
    {
	fprintf(gnuplot1, "%f %f\n", tb[i], tb1[i]);
	fprintf(gnuplot1, "%f %f\n", tb[i], tb6[i]);
    }
    for(i = 1; i < 10; i++)
	tb2[i] += tb2[i-1] + 2/3;
    for(i = 0; i < 10; i++)
    }
	tb3[i] = f1(tb2[i]);
	tb7[i] = InterLagrange(tb2, f1, i);
    }
    for(i = 0; i < 10; i++)
    }
	fprintf(gnuplot2, "%f %f\n", tb2[i], tb3[i]);
	fprintf(gnuplot2, "%f %f\n", tb2[i], tb7[i]);
    }
    for(i = 1; i < 20; i++)
	tb4[i] += tb4[i-1] + 2/3;
    for(i = 0; i < 20; i++)
    {
	tb5[i] = f1(tb4[i]);
	tb8[i] = INterLagrange(tb4, f1, i);
    }
    for(i = 0; i < 20; i++)
    {
	fprintf(gnuplot3, "%f %f\n", tb4[i], tb5[i]);
	fprintf(gnuplot3, "%f %f\n", tb4[i], tb8[i]);
    }
    fclose(gnuplot1);
    fclose(gnuplot2);
    fclose(gnuplot3);
    return 0;
}
