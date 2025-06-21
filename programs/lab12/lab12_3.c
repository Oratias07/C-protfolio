# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# define N 5


void Int_Sum(void* sum, void* num)
{
    *(int*)sum += *(int*)num;
}


void Int_Sub(void* sum, void* num)
{
    *(int*)sum -= *(int*)num;
}


void Init(void* p)
{
    *(int*)p = 0;
}


int Int_Comp(void* a, void* b)
{
    if (*(int*)a == *(int*)b) return 1;
    return 0;
}
    

int Do_It(void* sum, void** array, void(*p_Init)(void*), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*))
{
    int i;

    p_Init(sum);
    for (i = 0; i < N; i++)
    {
        // the current sum is equal to the element (if it is not the first element)
        if (i > 0 && p_Comp(sum, array[i])) return 1;

        // update the cumulative sum
        (i % 2) ? p_Sub(sum, array[i]) : p_Sum(sum, array[i]);
    }

    return 0; // is not found a condition fit number
}


int main()
{
    int num[] = { 5, 8, 23, 20, 23 }, i, answer, sum;
    void* p_num[N];

    for (i = 0; i < N; i++) p_num[i] = &num[i]; // linking the void* list to the int list

    answer = Do_It(&sum, p_num, Init, Int_Sum, Int_Sub, Int_Comp);

    printf("\nFor the integer list:\n{ ");
    for (i = 0; i < N; i++)
    {
        printf("%d", num[i]);
        if (i + 1 != N) printf(", ");
    }
    printf(" }\n");
    
    answer ? printf("The answer is 'Yes'.\n") : printf("The answer is 'No'.\n");

    return 0;
}

