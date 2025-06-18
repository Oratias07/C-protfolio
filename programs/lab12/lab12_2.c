# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

#define N 5
typedef enum { FALSE, TRUE } BOOL;
typedef BOOL (*sumFunc)(void *, void *, void *); // pointer to function

// functions pototype
BOOL Int_Sum(void *, void *, void *);
BOOL Float_Sum(void *, void *, void *);
BOOL Sum(BOOL(*f)(void *, void *, void *), void **p_num, void *number);


int main()
{ 
	int num[] = { 3, 5, 23, 5, 6 }, i, value;
	float  fnum[] = { 3.5, 5.0, 2.3, 5.8, 6.2 }, fvalue;
	void *p_num[N];
    sumFunc f;


    // INT round
    for (i = 0; i < N; i++) p_num[i] = &num[i];
    f = Int_Sum;
	printf("\nPlease enter an integer number: ");
	if ((scanf("%d", &value)) < 1)
    {
        printf("Error reading value.\n");
        return 1;
    }
	(Sum(f, p_num, &value)) ? printf("There is such sum\n") : printf("There is no such sum\n");

    // FLOAT round
    for (i = 0; i < N; i++) p_num[i] = &fnum[i];
    f = Float_Sum;
	printf("\nPlease enter a float number: ");
    if ((scanf("%f", &fvalue)) < 1)
    {
        printf("Error reading value.\n");
        return 1;
    }
	(Sum(f, p_num, &fvalue)) ? printf("There is such sum\n") : printf("There is no such sum\n");

    return 0;
}

BOOL Sum(BOOL(*f)(void *, void *, void *), void **p_num, void *number)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (f(p_num[i], p_num[j], number)) return TRUE; // found two numbers whose sum is 'number'
        }
    }
    return FALSE;
}

BOOL Int_Sum(void *a, void *b, void *c)
{
  if(*(int*)a + *(int*)b == *(int*)c) return TRUE;
  return FALSE;
}

BOOL Float_Sum(void *a, void *b, void *c)
{
  if(*(float*)a + *(float*)b == *(float*)c) return TRUE;
  return FALSE;
}
