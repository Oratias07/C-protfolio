# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// function prototype
double sum_square(int m, int n, float(*f)(int a));


float func1(int x){ return 1.0 / x; }
float func2(int x){ return x / 5.0; }


int main()
{
    float (*fp)(int); // pointer to function

    fp = func2;
    printf("\nThe sum of func2: %.5lf\n", sum_square(2, 13, fp));

    fp = func1;
    printf("The sum of func1: %.5lf\n", sum_square(1, 10000, fp));

    return 0;
}

/* calculating the sum of square of f function (sum from m to n) and returning */
double sum_square(int m, int n, float(*f)(int a))
{
    if (m == 0 && n == 0) return 0; 

    return (m == n) ? pow(f(m), 2) : pow(f(m), 2) + sum_square(m + 1, n, f);
}