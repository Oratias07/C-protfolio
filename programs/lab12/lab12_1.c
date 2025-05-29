# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

// functions pototype
float** allocate_matrix(float**, int, int);
void set_2d(float** a, int m, int n);
void print_2d(float** a, int m, int n);
void error_message(char* msg);
void free_all(float** a, int m, int n);


int main( )
{
	int m, n;
	float** a;

	printf("\nEnter m and n, for m*n array: \n");
	if ((scanf("%d %d", &m, &n)) < 2) error_message("Error read m and n.\n");

    a = allocate_matrix(a, m, n);

    // set values and print matrix
	set_2d(a, m, n);
    print_2d(a, m, n);

    free_all(a, m, n);
    return 0;   
}

/// @brief allocating a pointer to a pointer array
/// @param a pointer of array of pointers
/// @param m numbers of rows
/// @param n numbers of columns
/// @return the pointer of pointers
float** allocate_matrix(float** a, int m, int n)
{
    int i, j;

    a = (float**)malloc(m * sizeof(float*));
    if (a == NULL) error_message("Error allocated matrix.\n");

    for (i = 0; i < m; i++)
    {
        a[i] = (float*)malloc(n * sizeof(float));
        if (a[i] == NULL)
        {
            for (j = 0; j < i; j++) free(a[j]);
            free(a);
            error_message("Error allocated row.\n"); 
        }
    }

    return a;
}

void free_all(float** a, int m, int n)
{
    int i;

    if (a != NULL)
    {
        for (i = 0; i < m; i++)
        {
            free(a[i]);
        }
        free(a);
    }
}

// set an values into 2D matrix
void set_2d(float** a, int m, int n)
{
    int i, j, k = 1;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = k++;
        }
    }
}

// printing FLOAT matrix
void print_2d(float **a, int m, int n)
{
    printf("{\n");

    for (int i = 0; i < m; i++)
    {
        printf("{");

        for (int j = 0; j < n; j++)
        {
            printf("%6.2f", a[i][j]);
            if (j < n - 1) printf(", ");
        }

        (i < m - 1) ? printf("},\n") : printf("}\n");
    }

    printf("}\n");
}

void error_message(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}
